CC=g++
CPPFLAGS=-Wall -g -O0 -std=c++17
LDFLAGS=-Wall

UNAME_S=$(shell uname -s)
ifeq ($(UNAME_S),Darwin)
	BOOST_PREFIX=/usr/local/opt/boost
	CPPFLAGS+=-I$(BOOST_PREFIX)/include
	LDFLAGS+=-I$(BOOST_PREFIX)/lib -lboost_regex -lboost_iostreams
else
	ifeq ($(UNAME_S),Linux)
		LDFLAGS+=-L/usr/lib/x86_64-linux-gnu -lboost_regex -lboost_iostreams
	endif
endif

EXES=iostreams_test2 iostreams_test7 regex_test_01 lexical_cast_test format_test1
OBJS=$(EXES:=.o)
SRCS=$(OBJS:.o=.cc)

all: $(EXES)

.cc.o:
	$(CC) -c $< $(CPPFLAGS)

iostreams_test2: iostreams_test2.o
	$(CC) -o $@ $? $(LDFLAGS)

iostreams_test7: iostreams_test7.o
	$(CC) -o $@ $? $(LDFLAGS)

regex_test_01: regex_test_01.o
	$(CC) -o $@ $? $(LDFLAGS)

lexical_cast_test: lexical_cast_test.o
	$(CC) -o $@ $? $(LDFLAGS)

format_test1: format_test1.o
	$(CC) -o $@ $? $(LDFLAGS)

clean:
	rm -f $(EXES) *.o *~ a.out

.SUFFIXES:
.SUFFIXES: .cc .h .o 
.PHONY: all clean subdirs $(SUBDIRS)
