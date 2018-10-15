############################# Makefile ##########################
PROG = bin/Keno
CC = g++
CPPFLAGS = -O0 -g -W -Wall -pedantic -std=c++11
OBJS = main.o kenoBet.o

$(PROG) : $(OBJS)
	$(CC)	$(OBJS) -o $(PROG)
	mv *.o build/

main.o :
	$(CC) $(CPPFLAGS) -c src/main.cpp

kenoBet.o : include/kenoBet.h
	$(CC) $(CPPFLAGS) -c src/kenoBet.cpp

.PHONY: clean mrproper
clean:
	rm -f build/*.o
mrproper: clean
	rm -rf $(PROG)
