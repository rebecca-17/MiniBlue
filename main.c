#include <unistd.h>
#include <stdio.h>
#include "scroll.h"
#include <linux/input.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

int vx = 0, vy = 0;
char* color = "WHITE";
int degrees = 0;
char *speed = NULL;
bool passSpeed=false;

int Ourindex = 0;

void handler(unsigned int code) {
    printf("code: %u\t",code);
    if(code == KEY_UP) {
        //printf("right");
        vx--;
    }else if(code == KEY_DOWN) {
        //printf("left");
        vx++;
    }else if(code == KEY_RIGHT) {
        //printf("down");
        vy++;
    }else if(code == KEY_LEFT) {
        //printf("up");
        vy--;
    }else if(code == KEY_ENTER) {
        //printf("push");
        Ourindex++; ;
    }
    printf("\n");
}
void dot_roll() {

    char letters[] = {'A', 'Y', 'R', 'F','#'};

    open_display();

    float x = 0, y = 0;
    float dt = 0.05;

    open_input();
    while (1) {
        int ix = (int)x;
        int iy = (int)y;

        check_input(handler,10);
        clear_display();
        if (letters[Ourindex] == '#') {
            clear_display();
            break;
        }

        if(passSpeed){
            display_letter(letters[Ourindex], ix, iy, color, degrees, vx, vy);

        }
        else{
            display_letter(letters[Ourindex], ix, iy, color, degrees, 0, 0);

        }
        
        x += vx * dt;
        y += vy * dt;
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

        }
        else if (strcmp(argv[i], "-c")==0) {
            color=argv[i+1];
            i++;
            if (strcmp(color, "WHITE") != 0 && 
                strcmp(color, "RED") != 0 && 
                strcmp(color, "BLUE") != 0 && 
                strcmp(color, "GREEN") != 0) {
                printf(argv[0]);
                h(); 
                return 1; 
            }
            
        }
        else if (strcmp(argv[i], "-r")==0) {
            degrees = atoi(argv[i+1]);
            i++;
            
            if (degrees!=0 && 
                degrees!= 90 && 
                degrees != 180 && 
                degrees != 270) {
                printf(argv[0]);
                h(); 
                return 1; 
            }
            
        
        }
        else if (strcmp(argv[i], "-s")==0) {
            passSpeed=true;
        }
        else{
            printf(argv[0]);
            h();
            return 0;

        }
        
    }

	dot_roll();

    close_display();
	return 0;
}
