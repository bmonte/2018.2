############################# Makefile ##########################
PROG = bin/test
CC = g++
CPPFLAGS = -O0 -g -W -Wall -pedantic -std=c++11
OBJS = main.o pointer.o

$(PROG) : $(OBJS)
	$(CC)	$(OBJS) -o $(PROG)
	mv *.o build/

main.o :
	$(CC) $(CPPFLAGS) -c src/main.cpp

pointer.o : include/pointer.h
	$(CC) $(CPPFLAGS) -c src/pointer.cpp

.PHONY: clean mrproper
clean:
	rm -f build/*.o
mrproper: clean
	rm -rf $(PROG)
