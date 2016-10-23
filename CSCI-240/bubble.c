//bubble.c
//famous bubble sort
//implement the swap algorithm with pointers

#include <stdio.h>
#define MAX 9

//function prototypes
void printValues();
void sort();
void swap(int*, int*);

int values[] = {7, 3, 9, 4, 6, 1, 2, 8, 5};

int main(){
  printf("Before: \n");
  printValues();
  sort();
  printf("After: \n");
  printValues();

  return(0);
} // end main

void printValues(){
  for (int i = 0, i < (sizeof(values)/sizeof(values[0])), i++){
    printf (values[i])
}
}

void sort(){
  int counter1, counter2;
  for (counter1 = 0, counter1 < (sizeof(values)/sizeof(values[0])), counter1++){
    for (values[counter1], values[counter2]){
      if (values[counter1] < values[counter2]){
        swap(x, y)
  printValues()
}
}
}

  for (i in (values[] - 1)){
    for (j in (values[] - 1)){ 
      if (list[j] > list[j + 1]){
	swap (list[j], list [j+1])
}
}
} 
}

void swap(){
  temp = *valueA
  *valueB = *valueA
  valueB = temp
}
