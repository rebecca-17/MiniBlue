# Set a variable LDFLAGS. Use the variable as $(LDFLAGS)
LDFLAGS := -L ~/lib -lsense -lm

all: project
project: main.o display.o input.o
	cc -o project main.o display.o input.o $(LDFLAGS)

terminal: main.o terminal.o
	cc -o terminal main.o terminal.o $(LDFLAGS)

%.o: %.c project.h
	cc -g -c $< -I ~/include

clean:
	rm -f *.o project
run: project
	./project
