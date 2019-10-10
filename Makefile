.SUFFIXES: 
.SUFFIXES: .cc .o .h

EXES= list1 list2 vector1 deque1 set1 multiset0 mmap1 map1 algo1 find1 copy1 copy2 copy3 ioiter1 pq1 sort1
OBJS= $(EXES:=.o)
SRCS= $(EXES:=.cc)
CC= g++
CFLAGS= -Wall -g -std=c++11
CXXFLAGS= -Wall -g -std=c++11

.cc.o:
	$(CC) -c $< $(CFLAGS)

all: $(EXES)

clean:
	$(RM) -f $(EXES) $(OBJS) *~ a.out
