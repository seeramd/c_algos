IDIR = include
CC = gcc
CFLAGS = -g -Wall

ODIR = obj
DEPS = $(wildcard $(IDIR)/*.h)

SRCDIR = src

_OBJ = lists.o my_sort.o my_recurse.o my_search.o
_OBJ += main.o
OBJ = $(patsubst %,$(ODIR)/%,${_OBJ})

$(ODIR)/%.o: $(SRCDIR)/%.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

prog: $(OBJ)
	$(CC) -o bin/$@ $^ $(CFLAGS)

.PHONY: clean

clean:
	rm -f $(ODIR)/*.o *~ core $(IDIR)/*~
