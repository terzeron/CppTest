CC=g++

EXE=test

all: $(EXE)

$(EXE): test.o
	$(CC) -o $@ $< $(LDFLAGS)

clean:
	rm -f $(EXE) *.o *~ a.out

.SUFFIXES:
.SUFFIXES: .cc .h .o 
.PHONY: all clean subdirs $(SUBDIRS)
