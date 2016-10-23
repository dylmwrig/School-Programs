/* where the magic happens
 * contains:
 *   -first and last name
 *   -gpa
 *   -credit
 *   -date of graduation and birth
 *   -address
 *   -student reports in formats:
 *       -comprehensive
 *       -shortened
 *       -alphabetized
 *
 *
 */
#ifndef STUDENT_H
#define STUDENT_H

#include "address.h"
#include "date.h"
#include <iostream>
#include <string>

class Student{
  private:
    std :: string Fname, Lname;
    Address address;
    Date graduate, dob; //separate graduation and date of birth instances, but using the same class
    float gpa;
    int credit;

  public:
//setters
    void setFname(std :: string Fname);
    void setLname(std :: string Lname);
    void setGpa(float gpa);
    void setCredit(int credit);
/*    void setAddress(Address address);
    void setDob(Date dob);
    void setGraduate(Date graduate);
*/
//getters
    std :: string getFname();
    std :: string getLname();
    float getGpa();
    int getCredit();
    Address getAddress();
    Date getDob();
    Date getGraduate();
 
    std :: string fullReport();
    std :: string shortReport();
    std :: string alphaReport();

    Student(); //constructor
    Student(Address address, Date dob, Date graduate); 
    ~Student(); //destructor
};
#endif
