#include "scroll.h"
#include <stddef.h>
#include <stdio.h>
#include "sense.h"
#include <string.h>

#define WHITE 0xFFFF
#define BLACK 0x0000
#define RED   0xF800  
#define GREEN 0x07E0 
#define BLUE  0x001F  

pi_framebuffer_t *fb= NULL;

char letA[]="........"
            "..###..."
            ".#...#.."
            ".#...#.."
            ".#####.."
            ".#...#.."
            ".#...#.."
            ".#...#..";

char letY[] ="........"
             ".#...#.."
             ".#...#.."
             ".#...#.."
             "..#.#..."
             "...#...."
             "...#...."
             "...#....";

char letR[]="........"
            ".####..."
            ".#...#.."
            ".#...#.."
            ".####..."
            ".#.#...."
            ".#..#..."
            ".#...#..";

char letF[] = "........"
              ".####..."
              ".#......"
              ".#......"
              ".####..."
              ".#......"
              ".#......"
              ".#......";

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

int pm(int i) {
        return (i % 8 + 8) % 8;
}

void display_letter(char letter, int xOffset, int yOffset, char* color, int degrees, int vx, int vy){

    char *ltr=NULL;

    if(letter=='A') {
        ltr=letA;
    } else if(letter=='Y') {
        ltr=letY;
    } else if(letter=='R') {
        ltr=letR;
    }else if(letter=='F') {
        ltr=letF;
    } else {
        printf("Critical error\n");
        ltr=letA;
    }

    //sense_fb_bitmap_t *bm=fb->bitmap;

    clear_display(); 

    for(int i=0; i<8; i++) {
        for(int j=0; j<8; j++) {
            if(ltr[i+j*8]=='#') {
                int x, y;
                
                if (degrees == 0) {
                    x = pm(-i + xOffset -2 );
                    y = pm(j + yOffset);

                } else if (degrees == 90) {
                    x = pm(j+xOffset);
                    y = pm(7- (-i)+yOffset+2);
                    
                } else if (degrees == 180) {
                    x = pm(7 - (-i) + xOffset +2);
                    y = pm(7 - j + yOffset);
                } else if (degrees == 270) {
                    x = pm(7 - j + xOffset);
                    y = pm(-i + yOffset -2);
                }
                if((vx>10||vx<-10||vy>10||vy<-10)||(strcmp(color, "RED")==0))
                {
                    fb->bitmap->pixel[x][y] = RED;

                }
                else if (strcmp(color, "BLUE")==0){
                    fb->bitmap->pixel[x][y] = BLUE;

                }
                else if (strcmp(color, "GREEN")==0){
                    fb->bitmap->pixel[x][y] = GREEN;

                }
                else{
                    fb->bitmap->pixel[x][y] = WHITE;
                }           
            }
        }
    } 
}
