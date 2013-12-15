all: hello

mylib:
	gcc -fPIC -c mylib.c
	gcc -shared -o libmy.so mylib.o


main1.o: main1.c
	gcc -c main1.c

hello: main1.o mylib
	gcc -o hello main1.o -L/home/sunny/cpp-coding/hello-c -lmy

clean :
	rm -rf *.o hello
	rm -rf *.so hello
	ls
