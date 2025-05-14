#include <unistd.h>
#include <stdio.h>
#include "project.h"
#include <linux/input.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

int vx = 6, vy = 6;
char* color = "WHITE";
int degrees = 0;
int gemlocationX = 3, gemlocationY = 3;
int score=0;

void createGem(void) {
    gemlocationX = (rand() % 6) + 1;
    gemlocationY = (rand() % 6) + 1;
}

int search() {
    if((vx == gemlocationX) && (vy == gemlocationY)) {
        score++;
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
    while (score<8) {
        calibrate();
        if(check_shake()){
            show_score(score);
        }
             
        

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

int main(){
    

	dot_roll();

    close_display();
	return 0;
}
