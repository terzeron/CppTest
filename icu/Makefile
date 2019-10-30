CC=g++
CPPFLAGS=-Wall -g -O0 -std=c++17
LDFLAGS=-Wall

UNAME_S=$(shell uname -s)
ifeq ($(UNAME_S),Darwin)
    CC=g++-9
    ICU_PREFIX=/usr/local/opt/icu4c
    CPPFLAGS+=-I$(ICU_PREFIX)/include
    LDFLAGS+=-L$(ICU_PREFIX)/lib -liconv
else
    ifeq ($(UNAME_S),Linux)
        CPPFLAGS+=
        LDFLAGS+=
    endif
endif
LDFLAGS+=-licuuc

EXES=decompose codecvt_test
OBJS=$(EXES:=.o)
SRCS=$(OBJS:.o=.cc)

all: $(EXES)

codecvt_test: codecvt_test.o
	$(CC) -o $@ $? $(LDFLAGS)

decompose: decompose.o
	$(CC) -o $@ $? $(LDFLAGS)

.cc.o:
	$(CC) -c $< $(CPPFLAGS)

clean:
	rm -f $(EXES) *.o *~ a.out

.SUFFIXES:
.SUFFIXES: .cc .h .o 
.PHONY: all clean subdirs $(SUBDIRS)
