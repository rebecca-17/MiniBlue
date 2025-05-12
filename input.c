#include "sense.h"
#include "scroll.h"
#include <linux/input.h>
#include <stdio.h>

void open_input(void);
void close_input(void);
void check_input(void (*callback)(unsigned int code), int delay);

int dx = 0, dy = 0;

/* Program stops when 'running' is zero */
int running=1;

pi_joystick_t* joystick=NULL;

void open_input(void) {
    joystick=getJoystickDevice();
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