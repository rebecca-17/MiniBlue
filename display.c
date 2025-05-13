#include "scroll.h"
#include <stddef.h>
#include <stdio.h>
#include "sense.h"
#include <string.h>

#define WHITE 0xFFFF
#define BLACK 0x0000
#define GREEN 0x07E0 
#define BLUE  0x001F  

pi_framebuffer_t *fb= NULL;

char Wmap[] =   "########"
                "#......#"
                "#......#"
                "#......#"
                "#......#"
                "#......#"
                "#......#"
                "########";

void clear_display(void){
    if(fb) {
        clearFrameBuffer(fb,BLACK);
    }
}

void open_display(void){
    if(fb==NULL){
        fb=getFrameBuffer();
    }
}

void close_display(void){
    if (fb){
        clearFrameBuffer(fb, BLACK);
        freeFrameBuffer(fb);
        fb=NULL;
    }
}

void display_gem(int gemlocationX, int gemlocationY) {
    fb->bitmap->pixel[gemlocationX][gemlocationY] = GREEN;
}

void miniBecca(int xOffset, int yOffset) {
    int Rx, Ry;
    Rx = (xOffset);
    Ry = (yOffset);
    if (Rx >= 0 && Rx < 8 && Ry >= 0 && Ry < 8) {
        fb->bitmap->pixel[Rx][Ry] = BLUE;
    }
}

void display_map(char map,int xOffset, int yOffset , char* color, int degrees, int vx, int vy){
    
    char *object=NULL;
    
    if(map=='m') {
        object=Wmap;
    }else {
        printf("Critical error\n");
    }

    miniBecca(xOffset,yOffset);
     
    for(int i=0; i<8; i++) {
        for(int j=0; j<8; j++) {
            if(object[i+j*8]=='#') {
                int x, y;
                x = (i);
                y = (j);
                fb->bitmap->pixel[x][y] = WHITE;
            }
        }
}
}   
