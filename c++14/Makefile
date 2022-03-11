CC=g++
CPPFLAGS=-Wall -g -O0 -std=c++14
LDFLAGS=-Wall

EXES=lambda1 lambda2 variable_template binary_literal digit_separator deprecated_attribute
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
