""" crypto.py
    Implements a simple substitution cypher
"""
#menu just prints and returns input from user
#encode takes input 'scramble', converts it to uppercase and a list
#define two counter variables for loop and nested loop
#outer loop compares scramble's iterator to its length
#inner loop compares scramble's iterator position to character position in global alpha
#if there is a space just add one to the iterator so the space stays in the same position
#when the characters are the same, scramble's character will equal the equivalent position in global key
#use .join to join the list into a string and return the value
#do the same for decode but reverse, swapping alpha and key and changing names where appropriate

alpha = "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
key =   "XPMGTDHLYONZBWEARKJUFSCIQV"

def menu():
    print ("SECRET DECODER MENU")
    print ("0) Quit")
    print ("1) Encode")
    print ("2) Decode")
    response = input ("What do you want to do?")
    return response

def encode(scramble):
    scramble = scramble.upper() #convert to uppercase so as to avoid casing issues
    scramble = list(scramble) #separate the sequence
    counter = 0
    abc = 0

    while (counter < len(scramble)):

        if (scramble[counter] == " "): #skip whitespace
            counter = counter + 1

        while (scramble[counter] != alpha[abc]): #find the equivalent letter
            abc = abc + 1

        scramble[counter] = key[abc] #set letter equal to the letter in the equivalent key space
        counter = counter + 1
        abc = 0

    scramble = ''.join(scramble) #bring it back together
    return scramble

def decode(unscramble): #same as above but opposite
    unscramble = unscramble.upper()
    unscramble = list(unscramble)
    counter = 0
    abc = 0
    while (counter < len(unscramble)):

        if (unscramble[counter] == " "):
            counter = counter + 1

        while (unscramble[counter] != key[abc]):
            abc = abc + 1

        unscramble[counter] = alpha[abc]
        counter = counter + 1
        abc = 0

    unscramble = ''.join(unscramble)
    return unscramble

def main():
  keepGoing = True
  while keepGoing:
    response = menu()

    if response == "1":
      plain = input("text to be encoded: ")
      print(encode(plain))

    elif response == "2":
      coded = input("code to be decyphered: ")
      print (decode(coded))

    elif response == "0":
      print ("Thanks for doing secret spy stuff with me.")
      keepGoing = False

    else:
      print ("I don't know what you want to do...")

if (__name__ == "__main__"):
    main()
