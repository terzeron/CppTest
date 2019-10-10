SRCS=decompose.cc
OBJS=$(SRCS:.cc=.o)
EXE=$(SRCS:.cc=)

CFLAGS+=-I$(HOME)/include -I$(HOME)/include/unicode -g -Wall
LDFLAGS+=-L$(HOME)/lib -licuuc -licudata

.cc.o:
	$(CC) -c $< $(CFLAGS)

all: $(EXE)
	
decompose: $(OBJS)
	$(CC) -o $@ $(LDFLAGS) $<
