SUBDIRS=boost c++11 icu

CC=g++
CPPFLAGS=-Wall -g -O0 -std=c++17
LDFLAGS=-Wall

UNAME_S=$(shell uname -s)
ifeq ($(UNAME_S),Linux)
    CPPFLAGS+=
    LDFLAGS+=
endif

EXES=list1 list2 vector1 deque1 deque2 set1 multiset0 mmap1 map1 algo1 find1 copy1 copy2 copy3 ioiter1 pq1 sort1 cvt destruct_test c++01 compare_test daily_sum_test fsum hash_set_delete heap_test insertion_sort pq2 pqueue1 pqueue2 pqueue3 smallbuf_test sort_by_heap_test sort_check stl1 stl2 stl3 stl4 stl5 string_concat string_test sub test test1 test2 test3 test4 test5 test6 test7 test8 test9 test10 test11 test12 wchar_test sort_perf multimap_perf1 cpp_std_version cpp_std_version
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

deque2: deque2.o
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

cvt: cvt.o
	$(CC) -o $@ $< $(LDFLAGS)

destruct_test: destruct_test.o
	$(CC) -o $@ $< $(LDFLAGS)

c++01: c++01.o
	$(CC) -o $@ $< $(LDFLAGS)

compare_test: compare_test.o
	$(CC) -o $@ $< $(LDFLAGS)

daily_sum_test: daily_sum_test.o util.o
	$(CC) -o $@ $? $(LDFLAGS)

fsum: fsum.o 
	$(CC) -o $@ $< $(LDFLAGS)

hash_set_delete: hash_set_delete.o 
	$(CC) -o $@ $< $(LDFLAGS)

heap_test: heap_test.o 
	$(CC) -o $@ $< $(LDFLAGS)

insertion_sort: insertion_sort.o 
	$(CC) -o $@ $< $(LDFLAGS)

pq2: pq2.o 
	$(CC) -o $@ $< $(LDFLAGS)

pqueue1: pqueue1.o 
	$(CC) -o $@ $< $(LDFLAGS)

pqueue2: pqueue2.o 
	$(CC) -o $@ $< $(LDFLAGS)

pqueue3: pqueue3.o 
	$(CC) -o $@ $< $(LDFLAGS)

smallbuf_test: smallbuf_test.o 
	$(CC) -o $@ $< $(LDFLAGS)

sort_by_heap_test: sort_by_heap_test.o 
	$(CC) -o $@ $< $(LDFLAGS)

sort_check: sort_check.o 
	$(CC) -o $@ $< $(LDFLAGS)

srng1: srng1.o 
	$(CC) -o $@ $< $(LDFLAGS)

stl1: stl1.o 
	$(CC) -o $@ $< $(LDFLAGS)

stl2: stl2.o 
	$(CC) -o $@ $< $(LDFLAGS)

stl3: stl3.o 
	$(CC) -o $@ $< $(LDFLAGS)

stl4: stl4.o 
	$(CC) -o $@ $< $(LDFLAGS)

stl5: stl5.o 
	$(CC) -o $@ $< $(LDFLAGS)

string_concat: string_concat.o 
	$(CC) -o $@ $< $(LDFLAGS)

string_test: string_test.o 
	$(CC) -o $@ $< $(LDFLAGS)

sub: sub.o 
	$(CC) -o $@ $< $(LDFLAGS)

test: test.o 
	$(CC) -o $@ $< $(LDFLAGS)

test1: test1.o 
	$(CC) -o $@ $< $(LDFLAGS)

test2: test2.o 
	$(CC) -o $@ $< $(LDFLAGS)

test3: test3.o 
	$(CC) -o $@ $< $(LDFLAGS)

test4: test4.o 
	$(CC) -o $@ $< $(LDFLAGS)

test5: test5.o 
	$(CC) -o $@ $< $(LDFLAGS)

test6: test6.o 
	$(CC) -o $@ $< $(LDFLAGS)

test7: test7.o 
	$(CC) -o $@ $< $(LDFLAGS)

test8: test8.o 
	$(CC) -o $@ $< $(LDFLAGS)

test9: test9.o 
	$(CC) -o $@ $< $(LDFLAGS)

test10: test10.o 
	$(CC) -o $@ $< $(LDFLAGS)

test11: test11.o 
	$(CC) -o $@ $< $(LDFLAGS)

test12: test12.o 
	$(CC) -o $@ $< $(LDFLAGS)

wchar_test: wchar_test.o
	$(CC) -o $@ $< $(LDFLAGS)

sort_perf: sort_perf.o
	$(CC) -o $@ $< $(LDFLAGS)

multimap_perf1: multimap_perf1.o
	$(CC) -o $@ $< $(LDFLAGS)

.cc.o:
	$(CC) -c $< $(CPPFLAGS)

clean: $(SUBDIRS)
	$(RM) -f $(EXES) *.o *~ a.out

.SUFFIXES: 
.SUFFIXES: .cc .o .h
.PHONY: all clean subdirs $(SUBDIRS)
