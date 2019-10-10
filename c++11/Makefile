.SUFFIXES:
.SUFFIXES: .cc .h .o 
.PHONY: clean all

SRCS = test.cc
OBJS = $(SRCS:.cc=.o)
EXES = $(SRCS:.cc=)

CC = ${HOME}/bin/g++
CFLAGS += -m64 -g -Wall -O2 -I${HOME}/include -std=c++0x
LDFLAGS += -m64 -g -L${HOME}/lib #-std=c++0x

.cc.o:
	$(CC) -c $< $(CFLAGS)

all: $(EXES)

$(EXES): $(OBJS)
	$(CC) -o $@ $< $(LDFLAGS)

clean: 
	$(RM) -f *.o *.cc~ *.h~
