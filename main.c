#include <unistd.h>
#include <stdio.h>
#include "scroll.h"
#include <linux/input.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

int vx = 6, vy = 6;
char* color = "WHITE";
int degrees = 0;
int gemlocationX = 3, gemlocationY = 3;

void createGem(void) {
    gemlocationX = (rand() % 6) + 1;
    gemlocationY = (rand() % 6) + 1;
}

int search() {
    if((vx == gemlocationX) && (vy == gemlocationY)) {
        return 1;
    }else return 0;
}

void handler(unsigned int code) {
    //printf("code: %u\t",code);
    if(code == KEY_UP) {
        printf("right");
        if (!(vx <= 1)) {
        vx--;
        };
    }else if(code == KEY_DOWN) {
        //printf("left");
        if (!(vx >= 6)) {
        vx++;
        };
    }else if(code == KEY_RIGHT) {
        //printf("down");
        if (!(vy >= 6)) {
        vy++;
        };
    }else if(code == KEY_LEFT) {
        //printf("up");
        if (!(vy <= 1)) {
        vy--;
        };
    }else if(code == KEY_ENTER) {
        //printf("push");
        if (search()) {
            createGem();
        }
    }
    //printf("\n");
}
void dot_roll() {
    open_display();

    createGem();
    
    open_input();
    while (1) {

        check_input(handler,10);
        clear_display();
        display_gem(gemlocationX,gemlocationY);
        display_map('m', vx, vy, color, degrees, 0, 0);
        usleep(50000);
    }

    clear_display();
    close_display();
    close_input();
}

int main(int argc, char *argv[]){
    srand(time(NULL));
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
