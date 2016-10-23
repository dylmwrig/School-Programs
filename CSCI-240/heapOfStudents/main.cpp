/*Heap of Students
 * simple database created in C++ using memory allocation principles
 * classes required for address, date, and student
 * Student will have 2 date instances and 1 address instance 
 * all class instances must be stored on the heap! So use new
 *
 * use proper coding principles we'll be using from now on:
 * 1) header files with class definitions
 * 2) cpp files with implementation
 * 3) makefile to ensure dependencies are gucci
 * 4) GIT
 *
 * program flow:
 * 1) read input from text file
 *   -->each student's info will be stored on one line
 * 2) store data on the heap
 * 3) store all data for every student in a text file
 * 4) store abbreviated version with only full names in another text file
 * 5) store alphabetized version in another text file
 *
 * no vectors :  ^   (
 *
 * for parsing:
 * 1) read input file, line by line, using getline
 * 2) separate, with commas as delimiter
 * 3) store each bit on the heap in an array
 */

#include "address.h"
#include "date.h"
#include "student.h"

#include <string>
#include <iostream>
#include <sstream> //stringstream
#include <fstream> //filestream

int main()
{
//object instances to be passed into Student;
  /*Date graduate;

  address.setCity("Indianapolis");
  dob.setYear(2001);
  Student student(address, dob, graduate);
  Date myDob = student.getDob();
  int myYear = myDob.getYear();*/

//open the input file
  std :: ifstream inFile;
  inFile.open("input.txt");
  
 
  std :: string word;
  std :: string line; //variable for holding each line

  Student *studentArr = new Student[50]; //create array on heap of 50 students

  std :: string wordArr[14]; //holds each word/group of info from the file, delimited by commas
  int i = 0; //counter for array
  int studNum = 0; //moves between the students in the array

/*this code is where I started to understand this so I'll keep it for now

  studentArr[0].setFname("Tim");
  std :: string temp = studentArr[0].getFname();
  std :: cout << temp; 
*/
//  std :: cout << studentArr

  while (std :: getline(inFile, line))
    {
      std :: stringstream ss (line);
    
      while(std :: getline(ss, word, ','))
        {
          wordArr[i] = word;
          i++;
        } 

      studentArr[studNum].setFname(wordArr[0]); //store the word into my array
      studentArr[studNum].setLname(wordArr[1]);
      Address address;
      address.setAdd1(wordArr[2]);
      address.setCity(wordArr[3]);
      adidress.setState(wordArr[4]);
      //address.setZip(wordArr[5]);
      /*studentArr[studNum].setAddress(wordArr[2]);
      studentArr[studNum].setCity(wordArr[3]);
      studentArr[studNum].setState(wordArr[4]);
      studentArr[studNum].setZip(wordArr[5]);*/
      //studentArr[studNum].setCity(wordArr[3]);
      //studentArr[studNum].setState(wordArr[4]);
      //studentArr[studNum].setZip(wordArr[5]);
      //studentArr[1].setFname(wordArr[2]);
      std :: string myFname = studentArr[0].getFname();
      std :: string myLname = studentArr[0].getLname();
      std :: string yourFname = studentArr[1].getFname();
      std :: cout << "yo " << yourFname;  

      ss.clear(); //clear the stream
    }

//  std :: string output = student.getFname();
  i = 0;

/*  prints the array
  while (i < sizeof(wordArr)/sizeof(wordArr[0]))
    {
      std :: cout << wordArr[i] << std :: endl;
      i++;
    } */

  delete[] studentArr; //begone
}

//  inFile.close(); close the file

//  original new/delete attempts
//  int * p = new int[5];
//  delete[] p;
