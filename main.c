#include <unistd.h>
#include <stdio.h>
#include "scroll.h"
#include <linux/input.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

int vx = 2, vy = 2;
char* color = "WHITE";
int degrees = 0;
int Ourindex = 0;

void handler(unsigned int code) {
    printf("code: %u\t",code);
    if(code == KEY_UP) {
        //printf("right");
        if (!(vx > 8)) {
        vx++;
        };
    }else if(code == KEY_DOWN) {
        //printf("left");
        if (!(vx < 0)) {
        vx--;
        };
    }else if(code == KEY_RIGHT) {
        //printf("down");
        if (!(vy < 0)) {
        vy--;
        };
    }else if(code == KEY_LEFT) {
        //printf("up");
        if (!(vy > 8)) {
        vy++;
        };
    }else if(code == KEY_ENTER) {
        //printf("push");
        Ourindex++;
    }
    printf("\n");
}
void dot_roll() {

    char letters[] = {'A', 'Y', 'R', 'F','#'};

    open_display();

    float x = -2, y = -2;
    float dt = 0.05;

    open_input();
    while (1) {

        check_input(handler,10);
        clear_display();
        display_map('m', x, y, color, degrees, 0, 0);
        x = vx;
        y = vy;
        usleep(50000);
    }

    clear_display();
    close_display();
    close_input();
}

void h() {
    printf("                 Runs program. Shift Joystick to add velocity to the letter in a certain direction.\n");
    printf("                         Each additional shift speeds up the letter in that direction. Press down on the joystick to\n");
    printf("                         change the letter. Program exits after the joystick is pressed down 4 times, ie after\n");
    printf("                         a user cycles through all the letters {AYRF}.\n\n");
    printf("./scroll -h              Displays usage instructions for the program.\n\n");
    printf("./scroll -c COLOR        Sets the scrolling display color to the color given.\n");
    printf("                         COLOR may be one of WHITE, RED, GREEN or BLUE. Input directly with no quotes ie ./scroll -c RED\n\n");
    printf("./scroll -r DEGREES      Rotates the displayed letters counter-clockwise.\n");
    printf("                         DEGREES may be 0, 90, 180, or 270.\n\n");
    printf("./scroll -s              If the x-directio speed or y-direction \n");
    printf("                         speed goes above 10 in any direction the letter displays red.\n");
}



int main(int argc, char *argv[]){
    open_display();
    for(int i=1; i<argc; i++){
        if(strcmp(argv[i], "-h")==0){
            printf(argv[0]);
            h();
            return 0;

        } else{
            printf(argv[0]);
            h();
            return 0;

        }
        
    }

	dot_roll();

    close_display();
	return 0;
}
