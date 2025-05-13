#include "sense.h"
#include "project.h"
#include <linux/input.h>
#include <stdio.h>
#include <signal.h>
#include <time.h>
#include <unistd.h>

void open_input(void);
void close_input(void);
void check_input(void (*callback)(unsigned int code), int delay);

int dx = 0, dy = 0;

/* Program stops when 'running' is zero */
int running=1;

pi_joystick_t* joystick=NULL;
pi_i2c_t* device;
coordinate_t data;

void open_input(void) {
    joystick=getJoystickDevice();
    device=geti2cDevice();
    configureAccelGyro(device);
}
void close_input(void){
     if (joystick != NULL){
        freeJoystick(joystick);
        joystick = NULL;
    }


}
void check_input(void (*callback)(unsigned int code), int delay){
    pollJoystick(joystick, callback, delay);
}

void check_shake(void){
    getGyroPosition(device,&data);
    if(data.x >10 || data.y> 10 || data.z >10){
        printf("Rebecca is short");
        usleep(5000);
    }
    

}