/*
horse race program w/ OOD
2 classes in this program: one for the track, one for the horses
*/
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

using namespace std;

class Horse{
private:
    int position;

public:
    Horse(){ //Horse constructor
        position = 0;
    }

    void advance(){
        int randNum = rand() %2; //because it's a coin toss I'll just make horses advance if == 1 and just do nothing otherwise

        if (randNum == 1){
            this->position++;
//in recitation we chose to return position, but it's a property of the class so it should be changing anyway, and also advance is void? So it's probably unnecessary but idk why we did that in recitation
//return position;
        }
    }
    int getPosition(){
        return position;
    }
};

class Race{
private:
    int length;
    Horse h[5]; //array to hold 5 horse objects
public:
    Race()
    {
        length = 10; //edit this if you want to change the race distance
//I honestly do not fully understand the -> operator, I know it "dereferences" but don't understand all that that entails.
//I originally tried using a dot in place of the ->, so I believe it's just for accessing private values
        this -> length = length;
    }
//Race(int trueLength);
//I wasn't sure where to put these couple of lines at first:
//this -> length = trueLength;
//int trueLength;

    void printLane(int horseNum){
        bool isHere;

        for (int i = 0; i < length; i++){
            isHere = false;

            if (h[horseNum].getPosition() == i){ //if the horse's position is equal to the counter, print its number
                isHere = true;
                cout << horseNum;
            }

            if (!isHere){ //print a dot if the counter isn't equal to the horse's position just to show distance
                cout << ".";
            }
        }
        cout << endl;
    }

    void start(){
        bool finished; //sentry for most of what's happening in start()
        bool tieCheck; //checks for tie
        int winOrTie = -1; //initialized to be negative one because it will never = -1 as a result of the horses, only when initialized
        int originalWinner; //holds the first horse object that "wins" before checking for tie

        while (!finished){
//3 counters to move through each horse object and perform different tasks for each one:
            int a = 0; //victory counter
            int b = 0; //movement counter
            int c = 0; //print counter

            for (a; a < 5; a++){

                if (h[a].getPosition() == (length - 1)){
                    winOrTie = (a + 1); //stores the "winning" value to check if there's a tie
                    originalWinner = a; //print this if there is no tie
                    a = 5; //break the loop
                    b = 5; //setting all counters = 5 so the other loops don't ocntinue just makes the final output prettier
                    c = 5;
                }
                }


            if (winOrTie != -1){ //only runs once the value has been changed

                for (winOrTie; winOrTie < 5; winOrTie++){ //starts from where the first "winner" was so we can just check what's after it; if in the last position, this shouldn't run

                    if (h[winOrTie].getPosition() == (length - 1)){ //if anything else won at the same time, it's a tie!
                        cout << "Tie!";
                        tieCheck = true;
                        finished = true;
                    }
                }

                if (!tieCheck){ //if there wasn't a tie, print out the winner
                    cout << "Horse #" << originalWinner << " wins!";
                    finished = true;
                }
            }

            for (b; b < 5; b++){
                h[b].advance();
            }

            for (c; c < 5; c++){
                printLane(c);
            }

            if (!finished){ //makes it so it doesn't say "press enter to continue" when the program is finished
                cout << "Press enter to continue" << endl;
                cin.ignore(); //any key to continue
            }
        }
        }
};

int main(){
    srand (time(NULL)); //seed rng
    Race myRace;
    myRace.start(); //start does everything
    return 0;
}
