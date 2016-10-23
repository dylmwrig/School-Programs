#include <iostream>
#include <stdlib.h>
#include <string>
#include <time.h>

using namespace std;

int NUMCARDS = 52;
int DECK = 0;
int PLAYER = 1;
int COMP = 2;

int cardLoc [52];
const string suitName[] = {"hearts", "diamonds", "spades", "clubs"};
const string rankName[] = {"Ace", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine", "Ten", "Jack", "Queen", "King"};
const string playerName[] = {"deck", "player", "computer"};

void clearDeck(){
    int i;
    for (i = 0; i < 52; i++){
        cardLoc[i] = 0;
    }
}

void assignCard(int user){
    int shuffle;
    shuffle = rand() % 52;
//so we can modify the array without pointers, I didn't realize you could do that...
//I thought that would be the hard part about this program but I guess not
//however, why does it seem like the end result is only reflected in the final run through?
    cardLoc[shuffle] = user;
    /*int * shufPointer;
    shufPointer = &cardLoc[shuffle];
    *shufPointer = user;*/
}

void showDeck(){
    int counter = 0;
    int suitNum = 0;
    int rankNum = 0;
    cout << "location of all cards\n" << endl << "#\t\tcard\t\tlocation" << endl;
    for (counter; counter < 52; counter++){
        suitNum = int(counter/13);
        rankNum = counter - (suitNum*13);
        cout << (counter+1) << "\t" << rankName[rankNum] << " of " << suitName[suitNum] << "\t" << playerName[cardLoc[counter]] << endl;
    }
}

void showHand(int user){
    int counter = 0;
    int suitNum = 0;
    int rankNum = 0;
    if (user == 1){
        cout << "Displaying player hand" << endl;
    }
    else{
        cout << "Displaying computer hand" << endl;
    }
    for (counter; counter < 52; counter++){
        if (cardLoc[counter] == user){
            suitNum = int(counter/13);
            rankNum = counter - (suitNum*13);
            cout << rankName[rankNum] << " of " << suitName[suitNum] << endl;
        }
    }
}

int main(){
//"reseeds" the rng so that the number generated is truly random each time the program runs, without having to recompile each time.
    srand(time(NULL));
    int i;
    clearDeck();
    for (i = 0; i < 5; i++){
        assignCard(PLAYER);
        assignCard(COMP);
    }
    showDeck();
    showHand(PLAYER);
    showHand(COMP);
    return 0;
}
