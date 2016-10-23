"""
user selects if they want to add or delete a card at the highest menu
they can also decide to start quizzing themself on the highest menu
in addition to this, there will be a difficulty setting on the highest menu.  Whether the program will give you any flexibility in terms of spelling
within the quizzing state, they will be presented each definition (at first) and will be expected to give the word
word will be converted to all undercase and all spaces and punctuation will be removed
if the user selected an easier setting, iterate each time there is a character that is one letter away
if the iterated variable is > the allowed limit (the spelling forgiveness value), mark it as wrong
this feature is less for making it easier to mispell things, more to make it so a user isn't counted wrong if they just typed too quickly and made a typo
if it is correct, iterate the correct value on the object
when this value hits 3, ask the user if they would like to remove it from the quiz because they're pretty good on it
the quiz ends when the user has depleted the deck or they decide to quit

the notecard object does not need to do much, just store the values for name, definition, and correct count for each word

as for the spell check function:
give each character an x and y value relative to a center of the character H (meaning H is x = 0, y = 0) and don't count if distance is == 1 or root2.

consider giving this a guit later on
"""
from random import *
from math import *

class notecard (object): #I originally considered making the notecards a dictionary but also wanted to include other variables such as how many times the user has correctly answered it
#one other property I'd like to add is how quickly they answered it

    def __init__(self, name, definition, correct):

        self.setName(name)
        self.setDef (definition)
        self.setCorrect(correct)


    def setName(self, name):
        self.name = name

    def setDef (self, definition):
        self.definition = definition

    def setCorrect(self, correct):
        self.correct = correct

#this function is for the "forgiveness" feature of the program
#meant to make it so users do not get counted wrong on answers that they mistype, if they so wish
#it ONLY forgives if the letter is one key away, assigning each key an x,y value and using the pythagorean theorem to determine distance
#number of letters forgiven is set in the "difficulty" section of the program
#my program does not guarantee success for small words, however, as explained below (ctrl-f "if conditions check")
#current limitation of this feature: does not account for misplaced spaces.
def keyDistance(typeLetter, questLetter):
    distanceCheck = True
    distanceLoop = 0
    x = []
    y = []
    #first time around it will append the letter value for the answer, then the question the second time
    letter = typeLetter
    while (distanceCheck):
        if ((letter == ("q")) or (letter == ("w")) or (letter == ("e")) or (letter == ("r")) or (letter == ("t")) or (letter == "y") or (letter == "u") or (letter == "i") or (letter == "o") or (letter == "p")):
            y.append(1)

        elif ((letter == "a") or (letter == "s") or (letter == "d") or (letter == "f") or (letter == "g") or (letter == "h") or (letter == "j") or (letter == "k") or (letter == "l")):
            y.append(0)

        elif ((letter == "z") or (letter == "x") or (letter == "c") or (letter == "v") or (letter == "b") or (letter == "n") or (letter == "m")):
            y.append(-1)

        if ((letter == "y") or (letter == "h") or (letter == "n")):
            x.append(0)

        elif ((letter == "t") or (letter == "g") or (letter == "b")):
            x.append(-1)

        elif ((letter == "r") or (letter == "f") or (letter == "v")):
            x.append(-2)

        elif ((letter == "e") or (letter == "d") or (letter == "c")):
            x.append(-3)

        elif ((letter == "w") or (letter == "s") or (letter == "x")):
            x.append(-4)

        elif ((letter == "q") or (letter == "a") or (letter == "z")):
            x.append(-5)

        elif ((letter == "u") or (letter == "j") or (letter == "m")):
            x.append(1)

        elif ((letter == "i") or (letter == "k")):
            x.append(2)

        elif ((letter == "o") or (letter == "l")):
            x.append(3)

        elif (letter == ("p")):
            x.append(4)

        letter = questLetter
        distanceLoop += 1

        if (distanceLoop > 1):
            distanceCheck = False

    X = x[0] - x[1]
    Y = y[0] - y[1]

    pythag = sqrt (pow(X,2) + pow(Y,2))

    #the reason to be checking for 1.42 is because that is the lowest hundreds place decimal higher than root2 (because that is the diagonal distance between keys if they are diagonally adjacent)
    if (pythag < 1.42):
        return True

    else:
        return False

def main():
    deck = [] #array of "cards", each with words and definitions

    keepGoing = True
    intCheck = True

    difficulty = 0
    correct = 0
    counter = 0

    while (keepGoing):
        try: #try checks for valid number input, used a few times throughout this program with minor changes
            start =  input("What would you like to do?\n1\t\tadd a card\n2\t\tremove a card\n3\t\tdisplay all cards\n4\t\tquiz yourself\n5\t\tchange difficulty\n6\t\tquit")
            int(start)

        except ValueError:
            intCheck = False
            print ("I can't quite understand.")

        if (intCheck == False):
            print ("I can't quite understand.")
            intCheck = True

        elif (int(start)==1): #add a card
            name = input ("What is the word?")
            definition = input ("What is the definition?")
            card = notecard(name, definition, correct)
            deck.append(card) #append instances of the class rather than creating them in the list
            print(deck[counter].name, deck[counter].definition)
            counter += 1

        elif (int(start)==2): #allows the user to remove cards from the deck
            quitRemove = True
            removeCheck = True
            x = 0
            while (quitRemove): #make sure there are even cards to remove
                if (len(deck) == 0):
                    print ("Add some cards first!")
                    quitRemove = False

                else:
                    print ("What card do you want to remove?\n")

                    while (x < len(deck)): #give the users a list of cards so they know what they want to take
                        print ("Card", (x+1), ":", "\t\t", deck[x].name, "\n")
                        print ("Definition:", "\t", deck[x].definition, "\n")
                        x += 1

                    while (removeCheck):
                        cardRemove = (int(input ("Type the number of the card you would like to remove.  Otherwise, type '0'.")))
                        listDel = cardRemove - 1

                        if (cardRemove > len(deck)):
                            print ("That card does not exist.")

                        elif (cardRemove == 0):
                            removeCheck = False
                            quitRemove = False

                        else:
                            del deck[listDel]
                            counter -= 1
                            removeCheck = False
                            quitRemove = False

        elif (int(start)==3): #used for printing the deck
            x = 0
            if (len(deck) == 0):
                print ("Add some cards first!")

            else:
                while (x < len(deck)):
                    print ("Card", (x+1), ":", "\t\t", deck[x].name, "\n")
                    print ("Definition:", "\t", deck[x].definition, "\n")
                    x += 1
                    printCont = input ("Type anything to quit or press enter to continue.")
                    if (printCont != ""):
                        x = len(deck)

        elif (int(start)==4): #the actual quiz
            quizCont = True
            deleteCheck = True
            lengthCheck = False
            prevSelector = ""
            z = 0
            if (len(deck) == 0): #this block shows up a few times, might consider making this a function
                quizCont = False
                print ("\nAdd some cards first!")

            quizDeck = deck #quizDeck starts identical to deck, and is used so that cards which the user is strong on can be removed while testing
            while (z < len(quizDeck)):
                quizDeck[z].correct = 0
                z += 1

            while (quizCont):
                selector = randint(0, (len(deck)-1))

                while (selector == prevSelector): #ensures that the user isn't presented with the same card twice

                    if (len(deck) == 1):
                        break
                    selector = randint(0, (len(deck)-1))

                questCard = quizDeck[selector].name
                prevSelector = selector
                checkAns = []
                checkQuest = []
                ansCounter = 0
                mistakeCount = 0
                altDifficulty = difficulty
                correct = True

                print (quizDeck[selector].definition)
                answer = input ("What is the word?")
                answer = answer.lower()
                question = (quizDeck[selector].name)
                #this section is for checking the user's input.  It compares to common punctuation they might have but it will also convert everything to all lowercase
                #now that it checks and accounts for punctuation of the user, it should feed in the card's name in the same fashion.
                #I believe if I add the punctuation section to this code and just duplicate it or somehow integrate the card's reading, it should be simple to compare them
                while ((ansCounter < len(answer))):

                    if ((answer[ansCounter]==" ") or (answer[ansCounter] == "-") or (answer[ansCounter] == "_") or (answer[ansCounter] == ".") or (answer[ansCounter] == "/") or (answer[ansCounter] == "~")): #trying to check for \ as well but need to learn how to check for string literal
                        ansCounter += 1

                    else:
                        checkAns.append(answer[ansCounter])
                        ansCounter += 1
                ansCounter = 0

                while (ansCounter < len(question)):

                     if ((questCard[ansCounter]==" ") or (questCard[ansCounter] == "-") or (questCard[ansCounter] == "_") or (questCard[ansCounter] == ".") or (questCard[ansCounter] == "/") or (questCard[ansCounter] == "~")): #trying to check for \ as well but need to learn how to check for string literal
                        ansCounter += 1

                     else:
                        checkQuest.append(question[ansCounter])
                        ansCounter += 1

                ansCounter = 0

                #compares the lists
                while ((ansCounter < len(checkAns)) and (ansCounter < len(checkQuest))):

                    if (len(answer) > len(question) or len(question) > len(answer)):
                        #the program is able to give forgiveness for typos, but not for if the user added or subtracted characters
                        #so if the the word was "dog" and the user typed "eog", they would be correct if spelling forgiveness is on
                        #however, "deog" would be registered as incorrect
                        #this is something I'd like to modify later
                        ansCounter = (len(checkAns) + 1)
                        correct = False

                    elif (checkQuest[ansCounter] != checkAns[ansCounter]):

                        #if conditions check if the user has set a spelling forgiveness level and that the amount of letters in the word is at least twice as big, so users with 3 difficulty
                        #aren't guaranteed success on 3 letter words, for example

                        if (difficulty > 0):

                            if ((difficulty >= 2) and (len(questCard) < (difficulty * 2))):
                                altDifficulty = ((difficulty * 2) - (len(questCard)))

                                if (altDifficulty < 0): #make sure the difficulty isn't negative
                                    altDifficulty = 0

                            elif (difficulty == 1) and (len(questCard) <= 2):
                                altDifficulty = 0

                            spellCheck = keyDistance (checkQuest[ansCounter], checkAns[ansCounter])

                            if (spellCheck == True):
                                mistakeCount +=1

                            else:
                                correct = False

                        else:
                            correct = False
                            ansCounter = (len(checkQuest))

                        if (mistakeCount > altDifficulty):
                            correct = False
                            ansCounter = (len(checkQuest))

                    ansCounter += 1

                if (correct):
                    print ("You got it!")

                    quizDeck[selector].correct += 1

                    if (quizDeck[selector].correct >= 3): #if the user has gotten a card right many times, ask them if they'd like to remove it (the assumption is that they're pretty good on that card)

                        while (deleteCheck):
                            remove = input("\nWould you like to remove this card?\n1\t\tYes\n2\t\tNo")
                            try:
                                int(remove)

                            except ValueError:
                                continue

                            else:
                                deleteCheck = False

                            remove = int(remove)

                            if (remove == 1):
                                del quizDeck[selector]

                                if (len(quizDeck) == 0):
                                    quizCont = False
                                    lengthCheck = True


                else:
                    print ("You're wrong.")

                inputCheck = False

                if (lengthCheck):
                    break

                while True:
                    quizKeepGoing = input("Would you like to keep going?\n1\t\tYes\n2\t\tNo\n")

                    try:
                        int(quizKeepGoing)

                    except ValueError:
                        print ("I don't understand\n")
                        continue

                    else:
                        break

                if (inputCheck):
                    print ("\nI don't quite understand.\n")

                elif (int(quizKeepGoing) == 1):
                    quizCont = True

                elif (int(quizKeepGoing) == 2):
                    quizCont = False

                else:
                    print ("\nI don't quite understand.\n")


        elif (int(start)==5): #typo forgiveness
            clarity = True
            numCheck = True
            while clarity:
                difficulty =  input ("\nHow much spelling forgiveness would you like?\nSelect a number between 0 and 3.\n")
                while numCheck:

                    try:
                        int(difficulty)

                    except ValueError:
                        numCheck = True
                        print ("I don't quite understand")
                        difficulty = input("\nHow much spelling forgiveness would you like?\nSelect a number between 0 and 3.\n")

                    else:
                        numCheck = False

                if (numCheck == False):

                    difficulty = int(difficulty)
                    if ((difficulty > 3) or (difficulty < 0)):
                        print ("You must select a number between 0 and 3.")

                    else:
                        clarity = False

            difficulty = int(difficulty)

        elif (int(start)==6): #quit
            keepGoing = False

        else:
            print ("\nI don't quite understand.\n")

if (__name__=="__main__"):
    main()