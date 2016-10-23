CC = g++
#using g++ compiler
CFLAGS = 
#used to debug makefile, set to empty otherwise
parsing: parsing.o
	$(CC) $(CFLAGS) parsing.o -o parsing

parsing.o: parsing.cpp
	$(CC) $(CFLAGS) -c parsing.cpp
#compiles with just parsing

clean:
#nuke it
	rm -f *.o
	rm parsing

run: parsing
	./myLibrary
#works for "make run" command
