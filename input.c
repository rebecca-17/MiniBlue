#define _GNU_SOURCE
#include "sense.h"
#include "project.h"
#include <linux/input.h>
#include <stdio.h>
#include <signal.h>
#include <time.h>
#include <unistd.h>
#include <stdbool.h>
#include <math.h>

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

void calibrate(){
      while(getAccelData(device,&data) && data.x==0.0) {
            usleep(10000);
        }
}

int check_shake(void) {
    getAccelData(device, &data);
    
    if (fabs(data.x) > 1 || fabs(data.y) > 1) {
        while (true) {
            getAccelData(device, &data);
        
            if (fabs(data.x) < 0.5 && fabs(data.y) < 0.5) {
                break;
            }
             
        }
        return 1;
    }
    return 0;
}

    

