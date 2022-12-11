
all: main.c display.o combLogic.o
	gcc -Wall -O0 -o main.out main.c display.o combLogic.o

display.o: utils/display.c 
	gcc -Wall -O0 -o display.o -c utils/display.c

combLogic.o: mylib/combLogic.c 
	gcc -Wall -O0 -o combLogic.o -c mylib/combLogic.c

clear:
	rm -rf *.o
	rm -rf *.out