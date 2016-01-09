
MAKE := make
CC := gcc
CFLAGS := 

TOPDIR := $(shell pwd)

lib:fun1.o fun2.o fun3.o main.o
	ar r lib $?
#vpath %.o module1
main:fun1.o fun2.o fun3.o
#	$(CC) $^ -o $@

.PHONY: clean 

clean:
	-rm -f *.o 

