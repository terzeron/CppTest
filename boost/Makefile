CC=g++
CPPFLAGS=-g -Wall -O0 -std=c++11
LDFLAGS=-Wall -L/usr/lib/x86_64-linux-gnu/ -lboost_regex -lboost_iostreams

EXES=iostreams_test7 regex_test_01 lexical_cast_test format_test1
OBJS=$(EXES:=.o)
SRCS=$(OBJS:.o=.cc)

all: $(EXES)

.cc.o:
	$(CC) -c $< $(CPPFLAGS)

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
