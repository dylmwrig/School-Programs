/*take input of 
 *
 * getline takes two parameters: what you're looking at, and where you're going to put it. It keeps an internal placeholder within that file, etc, it outputs as a string
 * remember when using string stream to use the appropriate karats or however its spelled 
 * atoi converts a string to an integer
 * .c_str() converts a string to a c-style string (an array of characters)
 *
 *
*/
#include <iostream> //cout stuff
#include <fstream>  //used for files
#include <sstream>  //for string stream
#include <string>   //string

using namespace std;

/*int readFile (ifstream inFile){ //past attempt to turn bulk of program into a function
 
  while (!inFile.eof()){
    getline(inFile, line);
    i += 1;
}
  return 
}*/

int main(){
  int a, b, c,  sum, i = 0; //holds the numbers, sum is self explanatory
  string line; //holds the lines themselves
  string word = " "; //holds the individual words 
  string fakeNum; //string that wants to be a number. Follow your dreams

  //const char* may be something to add to these file definitions below
  ofstream outFile; //file I'm writing to: remember that these do not use ()
  ifstream inFile; //file I'm reading from
  inFile.open("input.txt"); //open the file I'm reading from 
  outFile.open("output.txt"); //open the file I'm writing to for editing
  
  stringstream ss; //stringstream allows for text conversion

  /*while (!inFile.eof()) //originally set the size of an array in which I was originally holding each individual word (didn't research stringstream properly, wasted some time here)
  {
    cout << "eof # 1!" << endl;
    getline(inFile, line);
    istringstream iss1 (line);
 
    while (iss1 >> word) 
      {
        i += 1;
        cout << "i" << i << endl;
      }
  }
  inFile.close();
  inFile.open("input.txt");
  cout << "We really out here " << i << endl;
  string wordList [i];
  i = 0;*/

 //inFile.is_open() is also pretty decent
 // while (!inFile.eof())//while this isn't the end of the file
  while (getline (inFile, fakeNum, ',')) //while we're getting stuff from the file...would eof, as originally used, be better in any way?  
 {
      ss.clear(); //clear the string stream to avoid weird errors
     // line >> word; //receives input from the file to the line variable
     // cout >> line; this line was giving me problem

    //very crude way of sorting the input with delimiters with different variable types
    //come back later and try to do this with a function or OOP
      ss << fakeNum; //slip the "string" into the stream
      ss >> a;       //stream stuff goes back into an integer
      ss.clear();    //clear it everytime!
      getline (inFile, fakeNum, ',');
      ss << fakeNum;
      ss >> b;
      ss.clear();
      getline (inFile, fakeNum, '\n'); //we're at the end so no need to separate by commas
      ss << fakeNum;
      ss >> c;
   
      if (word == " ") //if the word hasn't been changed, getline...this solution irks me a lot, find a better solution for this
        {
          getline (inFile, word);
        }

      if (sum == 0) //same idea and same sentiment for this part
        {
          sum = a + b + c; //add the nums together to set the print amount
        }
   
   //debugging attempts

   /*   cout << "My word" <<  word << endl;
      cout << "My stream" << iss.str() << endl;
      while (getline(iss, word, ',')){
        
          cout << "B " << b << " " << (b + 1) << endl;
}
        cout << "That's my word" << word << endl;
}*/
     
   /* while (iss >> word) //while there are words to input
       
      {
        i += 1;
          wordList[i] = word;
        cout << "my word" <<  word << endl; // <<  wordList[i];
      } */
 }

  for (i; i < sum; i++)
    {
      outFile << word; //place word in the file

      if (i != (sum - 1)) //while we're not on the last word
        { 
         outFile << ","; //place a comma, no spaces
        }
    }
  outFile << endl;
  inFile.close(); //close your files!
  outFile.close();
  return 0;
}
