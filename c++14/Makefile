CC=g++
CPPFLAGS=-Wall -g -O0 -std=c++14 -pthread
LDFLAGS=-Wall

EXES=lambda1 lambda2 variable_template binary_literal digit_separator deprecated_attribute make_unique exchange heterogeneous_lookup shared_locking1 shared_locking2 shared_locking3 quoted_string user_defined_literal1 user_defined_literal2 user_defined_literal3 user_defined_literal4 integer_sequence1 integer_sequence2 integer_sequence3 test1
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
