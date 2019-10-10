CC=g++
CPPFLAGS=-g -Wall -O0 -std=c++11
LDFLAGS=-Wall 

all: test

test: test.o
	$(CC) -o $@ $< $(LDFLAGS)

clean:
	rm -f $(EXES) *.o *~ a.out

.SUFFIXES:
.SUFFIXES: .cc .h .o 
.PHONY: all clean subdirs $(SUBDIRS)
