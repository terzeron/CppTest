SUBDIRS=boost c++11 icu

CC:=g++
CPPFLAGS:=-Wall -g -O0 -std=c++11
LDFLAGS:=-Wall

EXES=list1 list2 vector1 deque1 set1 multiset0 mmap1 map1 algo1 find1 copy1 copy2 copy3 ioiter1 pq1 sort1
OBJS=$(EXES:=.o)
SRCS=$(EXES:=.cc)

all: $(EXES) $(SUBDIRS)

subdirs: $(SUBDIRS)

$(SUBDIRS):
	$(MAKE) -C $@ $(MAKECMDGOALS)

algo1: algo1.o
	$(CC) -o $@ $< $(LDFLAGS)

copy1: copy1.o
	$(CC) -o $@ $< $(LDFLAGS)

copy2: copy2.o
	$(CC) -o $@ $< $(LDFLAGS)

copy3: copy3.o
	$(CC) -o $@ $< $(LDFLAGS)

deque1: deque1.o
	$(CC) -o $@ $< $(LDFLAGS)

find1: find1.o
	$(CC) -o $@ $< $(LDFLAGS)

ioiter1: ioiter1.o
	$(CC) -o $@ $< $(LDFLAGS)

list1: list1.o
	$(CC) -o $@ $< $(LDFLAGS)

list2: list2.o
	$(CC) -o $@ $< $(LDFLAGS)

map1: map1.o
	$(CC) -o $@ $< $(LDFLAGS)

mmap1: mmap1.o
	$(CC) -o $@ $< $(LDFLAGS)

multiset0: multiset0.o
	$(CC) -o $@ $< $(LDFLAGS)

pq1: pq1.o
	$(CC) -o $@ $< $(LDFLAGS)

set1: set1.o
	$(CC) -o $@ $< $(LDFLAGS)

sort1: sort1.o
	$(CC) -o $@ $< $(LDFLAGS)

vector1: vector1.o
	$(CC) -o $@ $< $(LDFLAGS)

.cc.o:
	$(CC) -c $< $(CPPFLAGS)

clean: $(SUBDIRS)
	$(RM) -f $(EXES) *.o *~ a.out

.SUFFIXES: 
.SUFFIXES: .cc .o .h
.PHONY: all clean subdirs $(SUBDIRS)
