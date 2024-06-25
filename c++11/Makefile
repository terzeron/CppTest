CC=g++
CPPFLAGS=-Wall -g -O0 -std=c++11
LDFLAGS=-Wall

EXES=test move move1 move2 move3 shared_ptr lvalue1 lvalue2 rvalue_reference xvalue1 prvalue1 string_back factory static_cast1 static_cast2 static_cast3 static_cast4 static_cast5 static_cast6 async1
OBJS=$(EXES:=.o)
SRCS=$(OBJS:.o=.cc)

all: $(EXES)

.cc.o:
	$(CC) -c $< $(CPPFLAGS)

test: test.o
	$(CC) -o $@ $? $(LDFLAGS)

clean:
	rm -f $(EXES) *.o *~ a.out

.SUFFIXES:
.SUFFIXES: .cc .h .o 
.PHONY: all clean subdirs $(SUBDIRS)
