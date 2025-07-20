# Mini Blue- Raspberry Pi Animation

*A collaborative project by Rebecca Forman and Arron Ye for our Intro to Systems Programming course.*

This program is a game in which you control Mini Blue (a blue square) to collect 8 gems (green squares) on a Raspberry Pi LED display.

# Instructions:
    To start the program, simply place the Raspberry Pi on a flat surface, ensuring it is not moving, then start the program via

    make run

To control Mini Blue, use the joystick to move it to the gems. Once you are on top of a gem press into the joystick to collect it. After each successful collection, a new gem will spawn. After 8 gems are collected, the game will end. To check how many gems you have collected, simply shake the Raspberry Pi, each green line displayed represents a gem collected.   

Additional commands:  

    make all -> compiles the files  
    make clean -> removes the compiled files  
    ./project -> runs the game  


### What Rebecca contributed: 
- Developed the code to display the score once the Raspberry Pi is shaken
- Terminated the game once eight gems are collected
- Designed the border

### What Arron contributed:
- Developed the code to make Mini Blue move
- Implemented the border boundaries
- Created the code to randomly generate gem spawns

### What we learned:
- Created a functional program using C and the Raspberry Pi
- Connected joystick and accelerometer readings to functionality in the program
- Teamwork, communication, and patience is key




    


