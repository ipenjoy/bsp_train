
MAKE := make
CC := gcc
CFLAGS := 

TOPDIR := $(shell pwd)


VPATH = ./module1:./module2:./module3
#vpath %.o module1
main.o:file_1_1.c file_2_2.c file_3_2.c main.c
	$(CC) $^ -o $@

.PHONY: clean

clean:
	-rm -f *.o

