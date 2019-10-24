CC=g++

UNAME_S=$(shell uname -s)
ifeq ($(UNAME_S),Darwin)
    CC=g++-9
    ICU_PREFIX=/usr/local/opt/icu4c
    CPPFLAGS+=-I$(ICU_PREFIX)/include
    LDFLAGS+=-L$(ICU_PREFIX)/lib
else
    ifeq ($(UNAME_S),Linux)
        CPPFLAGS+=
        LDFLAGS+=-L/usr/lib/x86_64-linux-gnu
    endif
endif
LDFLAGS+=-licuuc -liconv

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
