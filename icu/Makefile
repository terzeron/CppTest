CC=g++
CFLAGS=-g -Wall -O0 -std=c++11 -I/usr/include/unicode
LDFLAGS=-Wall -L/usr/lib/x86_64-linux-gnu/ -licuuc

EXES=codecvt_test decompose
OBJS=$(EXES:=.o)
SRCS=$(OBJS:.o=.cc)

all: $(EXES)

codecvt_test: codecvt_test.o
	$(CC) -o $@ $? $(LDFLAGS)

decompose: decompose.o
	$(CC) -o $@ $? $(LDFLAGS)

.cc.o:
	$(CC) -c $< $(CFLAGS)

clean:
	rm -f $(EXES) *.o *~ a.out

.SUFFIXES:
.SUFFIXES: .cc .h .o 
.PHONY: all clean subdirs $(SUBDIRS)
