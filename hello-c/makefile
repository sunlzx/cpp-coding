all: hello

# I am a comment, and I want to say that the variable CC will be
# the compiler to use.
#CC=g++
CC=gcc
# Hey!, I am comment number 2. I want to say that CFLAGS will be the
# options I'll pass to the compiler.
CFLAGS=-c -Wall

mylib:
	$(CC) -fPIC -c mylib.c
	$(CC) -shared -o libmy.so mylib.o


main1.o: main1.c
	gcc -c main1.c

hello: main1.o mylib
	gcc -o hello main1.o -L/home/sunny/cpp-coding/hello-c -lmy

run: hello
	./hello



.PHONY: clean
clean:
	#-lss #- 忽略出错命令
	rm -rf *.o hello

.PHONY: cleanso
cleanso:
	rm -rf *.so
