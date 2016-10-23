/*meat for the Address.h skeleton
 *
 */
#include "address.h" //include the address header
//#include <string> //do I need to include this as well?
#include <iostream>

//getters
void Address :: setAdd1(std :: string address1){
  Address :: address1 = address1;
}
void Address :: setAdd2(std :: string address2){
  Address :: address2 = address2;
}
void Address :: setState(std :: string state){
  Address :: state = state;
}
void Address :: setCity(std :: string city){
  Address :: city = city;
}
void Address :: setZip(int zip){
  Address :: zip = zip;
}

//getters
std :: string  Address :: getAdd1(){
  return address1;
}
std :: string Address :: getAdd2(){
  return address2;
}
std :: string Address :: getState(){
  return state;
}
std :: string Address :: getCity(){
  return city;
}
int Address :: getZip(){
  return zip;
}

void Address :: printFormat(){
  std :: cout << address1 << "," << address2 << "," << state << "," << city << "," << zip << std :: endl;
}
