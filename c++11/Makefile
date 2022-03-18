CC=g++
CPPFLAGS=-Wall -g -O0 -std=c++11
LDFLAGS=-Wall

EXES=test move move1 move2 move3 shared_ptr lvalue1 lvalue2 string_back rvalue_reference factory static_cast1 static_cast2 static_cast3 xvalue1
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
