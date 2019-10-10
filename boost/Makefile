.SUFFIXES:
.SUFFIXES: .cc .c .h .o .v
.PHONY: test clean

SRCS = regex_test_01.cc
EXES = regex_test_01

CC = g++
CFLAGS += -m64 -g -Wall -O0
LDFLAGS += -m64
LIB = -L/usr/lib64/boost -lboost_regex
INCLUDE =

.cc.o:
	@echo "+--------------------------------"
	@echo "| Compile $<                     "
	@echo "+--------------------------------"
	$(CC) -c $< $(CFLAGS) $(INCLUDE)

all: $(EXES) TAGS

TAGS: $(SRCS)
	etags $^

regex_test_01: regex_test_01.o
	@echo "+-------------------------------+"
	@echo "| regex_test_01                 |"
	@echo "+-------------------------------+"
	$(CC) -o $@ $^ $(LDFLAGS) $(LIB)

clean:
	@echo "+--------------------------------"
	@echo "| Remove all binray files        "
	@echo "+--------------------------------"
	rm -f $(EXES) *.o *~ core.[0-9][0-9]* core TAGS tags vgcore.[0-9][0-9]*
