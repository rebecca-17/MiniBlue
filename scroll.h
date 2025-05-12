#ifndef SCROLL_H
#define SCROLL_H


void open_input(void);
void close_input(void);
void check_input(void (*callback)(unsigned int code), int delay);
void clear_display(void); 
void open_display(void);
void close_display(void);
void display_letter(char letter, int xOffset, int yOffset, char* color, int degrees, int vx, int vy);

#endif