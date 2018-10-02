############################# Makefile ##########################
PROG = bin/Pratica
CC = g++
CPPFLAGS = -O0 -g -W -Wall -pedantic -std=c++11
OBJS = main.o fraction.o

$(PROG) : $(OBJS)
	$(CC)	$(OBJS) -o $(PROG)
	mv *.o build/

main.o :
	$(CC) $(CPPFLAGS) -c src/main.cpp

fraction.o : include/fraction.h
	$(CC) $(CPPFLAGS) -c src/fraction.cpp

.PHONY: clean mrproper
clean:
	rm -f *.o
mrproper: clean
	rm -rf $(PROG)
