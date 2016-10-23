/*contains all bits of address information, including:
 *    -address 1
 *    -address 2
 *    -city
 *    -state
 *    -zip code
 *All are of data type str, save for zip, which is in forextra functrionality
 *
 *as we are mucking around in the heap, include destructors
 *This is a class which will be called in the student class.
 */
#ifndef ADDRESS_H
#define ADDRESS_H
#include <iostream>
#include <string>

class Address
{
  private:
    std :: string address1, address2, city, state;
    int zip;

  public:
//setters
    void setAdd1(std :: string address1);
    void setAdd2(std :: string address2);
    void setCity(std :: string city);
    void setState(std :: string state);
    void setZip(int zip);

//getters
    std :: string getAdd1();
    std :: string getAdd2();
    std :: string getCity();
    std :: string getState();
    int getZip();
    void printFormat();
    
};
#endif //terminates ifndef
