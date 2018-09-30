############################# Makefile ##########################
PROG = bin/test
CC = g++
CPPFLAGS = -O0 -g -W -Wall -pedantic -std=c++11
OBJS = main.o int_ranges.o

$(PROG) : $(OBJS)
	$(CC)	$(OBJS) -o $(PROG)
	mv *.o build/

main.o :
	$(CC) $(CPPFLAGS) -c src/main.cpp

int_ranges.o : include/int_ranges.h
	$(CC) $(CPPFLAGS) -c src/int_ranges.cpp

.PHONY: clean mrproper
clean:
	rm -f build/*.o
mrproper: clean
	rm -rf $(PROG)
