all: monitor

# I am a comment, and I want to say that the variable CC will be
# the compiler to use.
#CC=g++
CC=gcc
# Hey!, I am comment number 2. I want to say that CFLAGS will be the
# options I'll pass to the compiler.
CFLAGS=-c -Wall -O2




tpool.o: tpool.c tpool.h
	$(CC) $(CFLAGS) tpool.c

main.o: main.c
	$(CC) $(CFLAGS) main.c

monitor: tpool.o main.o
	$(CC) -o monitor tpool.o main.o -lpthread 




.PHONY: clean
clean:
	rm -rf *.o

