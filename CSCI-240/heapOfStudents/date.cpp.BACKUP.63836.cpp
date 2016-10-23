/*
 *
 */

#include "date.h"
#include <iostream>
#include <string> 

void Date :: setDay(int day){
  Date :: day = day;
}

void Date :: setMonth(int month){
  Date :: month = month;
}

void Date :: setYear(int year){
  Date :: year = year;
}

int Date :: getDay(){
  return day;
}

int Date :: getMonth(){
  return month;
}

int Date :: getYear(){
  return year;
}

<<<<<<< HEAD
void Date :: printFormat(){
  std :: cout << day << ',' <<  month << ',' <<  year << std :: endl;
}

Date :: Date(){
}

Date :: ~Date(){
=======
Date :: Date(){
  month = 1;
  day = 1;
  year = 2000;
}

Date :: Date(int m, int d, int y){
  month = m;
  day = d;
  year = y;
}

Date :: ~Date(){

>>>>>>> test
} 
