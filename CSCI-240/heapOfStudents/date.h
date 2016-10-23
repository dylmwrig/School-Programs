/* contains the following:
 *    -day
 *    -month
 *    -year
 *
 * this class will be called twice by student: 
 *    -once for birthday
 *    -once for graduation day
 */

#ifndef DATE_H
#define DATE_H

#include <iostream>
#include <string> 

class Date{
  private:
    int day, month, year;
  
  public:
    void setDay(int day);
    void setMonth(int month);
    void setYear(int year);
    int getDay();
    int getMonth();
    int getYear();

    void printFormat();
    Date(); //constructor: requires a destructor because we're working on the heap
    Date(int m, int d, int y); //format is m,d,y
    
    ~Date();
};
#endif
