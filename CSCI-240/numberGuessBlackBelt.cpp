#include <iostream>
#include <stdlib.h>
#include <time.h>

using namespace std;

//reverse number guessing program
//user comes up with number for computer to guess
//don't use rng

void compGuess(){

    bool correct = false;
//computer's first guess will be 50, to cast the widest net possible
    int guess = 50;
    int lastGuess = 0;
//initializing the bounds
//computer will simply guess the median between these bounds
    int high = 101;
    int low = 1;
//just keeps track of the amount of guesses
    int counter = 0;
    char answer;
    //sentry correct only modified once the user tells the computer they are correct
    while (correct == false){
        counter += 1;
        cout << "Guess #" << counter << endl;
        cout << "\nWas your number " << guess << endl;
        cout << "h\t\ttoo high\nl\t\ttoo low\nc\t\tcorrect" << endl;
        cin >> answer;
//makes lower bound whatever the lower guess is
        if (answer == 'l'){
            low = guess;
        }
//and vice versa
        else if (answer == 'h'){
            high = guess;
        }
//midpoint between the bounds
        guess = ((low + high)/2);
        if (lastGuess == guess){
//checks which bound we are moving towards, because this issue will only arise in the upper and lowermost bounds.
/*these lines were only necessary when I had the upper bound at 100 rather than 101
            if (low == 1){
                guess--;
            }
            else{
                guess++;
            }*/
        }
//lastGuess stores the last guess so the computer doesn't give the same number twice
        lastGuess = guess;
        if (answer == 'c'){
            correct = true;
        }
    }
}

void youGuess(){
    int guess = 0;
    int attempt;
    bool keepGoing = true;
    int goal = rand() %101;
    cout << "I'm thinking of a number between 1 and 100, what do you think it is?\nI'll tell you if you're low, high, or got it right.\nGood luck!" << endl;
    while (keepGoing == true){
        cout << "What is your guess?" << endl;
        cin >> attempt;
        guess += 1;
        if (attempt == goal){
            keepGoing =false;
        }
        else if (attempt > goal){
            cout << "Too high!" << endl;
        }
        else if (attempt < goal){
            cout << "Too low!" << endl;
        }
    }
    cout << "Correct! It took " << guess << " tries." << endl;
}

main(){
    srand (time(NULL));
    int choice;
    cout << "Would you like the computer to guess the number or would you like to?\n1.\tcomputer guesses\n2.\tyou guess" << endl;
    cin >> choice;
    if (choice == 1){
        compGuess();
    }
    else{
        youGuess();
    }
}
