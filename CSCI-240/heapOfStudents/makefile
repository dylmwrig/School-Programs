#makefile for heap of students

CC = g++ #compiler we're using is g++
CFLAGS = -g -Wall #-g = debugging info, -Wall = all warnings

heapOfStudents: main.o address.o date.o student.o
	$(CC) $(CFLAGS) main.o address.o date.o student.o -o heapOfStudents

address.o: address.cpp address.h
	$(CC) $(CFLAGS) -c address.cpp

date.o: date.cpp date.h
	$(CC) $(CFLAGS) -c date.cpp

student.o: student.cpp student.h
	$(CC) $(CFLAGS) -c student.cpp

main.o: main.cpp address.h date.h student.h
	$(CC) $(CFLAGS) -c main.cpp

clean: #remove all files made here
	rm *.o
	rm heapOfStudents

run:	heapOfStudents
	./heapOfStudents

valgrind: #check for memory leaks
	valgrind --tool=memcheck ./heapOfStudents
