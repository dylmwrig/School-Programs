/*
 *
 *
 */
#include "student.h"
#include "date.h"
#include "address.h"

#include <iostream>

//setters
void Student :: setFname(std :: string Fname){
  Student :: Fname = Fname; 
}

void Student :: setLname(std :: string Lname){
  Student :: Lname = Lname; 
}

void Student :: setGpa(float gpa){
  Student :: gpa = gpa; 
}

void Student :: setCredit(int credit){
  Student :: credit = credit; 
}

/*void Student :: setAddress(Address address){
  address = address;
}

void Student :: setDob(Date dob = dob){
  dob = dob;
}

void Student :: setGraduate(Date graduate = graduate){
  graduate = graduate;
}*/

//getters
std :: string Student :: getFname(){
  return Fname;
}

std :: string Student :: getLname(){
  return Lname;
}

float Student :: getGpa(){
  return gpa;
}

int Student :: getCredit(){
  return credit;
}

Address Student :: getAddress(){
  return address;
}

Date Student :: getDob(){
  return dob;
}

Date Student :: getGraduate(){
  return graduate;
}

Student :: Student(){
    
}

Student :: Student(Address address, Date dob, Date graduate){
  address = address;
  dob = dob;
  graduate = graduate;
}

Student :: ~Student(){

}
