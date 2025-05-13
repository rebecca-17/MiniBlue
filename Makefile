# Set a variable LDFLAGS. Use the variable as $(LDFLAGS)
LDFLAGS := -L ~/lib -lsense -lm

all: scroll
scroll: main.o display.o input.o
	cc -o scroll main.o display.o input.o $(LDFLAGS)

terminal: main.o terminal.o
	cc -o terminal main.o terminal.o $(LDFLAGS)

%.o: %.c project.h
	cc -g -c $< -I ~/include

clean:
	rm -f *.o scroll
run: scroll
	./scroll
