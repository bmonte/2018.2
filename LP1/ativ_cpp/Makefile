############################# Makefile ##########################
PROG = bin/Pratica
CC = g++
CPPFLAGS = -O0 -g -W -Wall -pedantic -std=c++11
OBJS = main.o sapo.o

$(PROG) : $(OBJS)
	$(CC)	$(OBJS) -o $(PROG)
	mv *.o build/

main.o :
	$(CC) $(CPPFLAGS) -c src/main.cpp

sapo.o : src/sapo.h
	$(CC) $(CPPFLAGS) -c src/sapo.cpp

.PHONY: clean mrproper
clean:
	rm -f *.o
mrproper: clean
	rm -rf $(PROG)
