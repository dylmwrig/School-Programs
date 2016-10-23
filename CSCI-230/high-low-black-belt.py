#tell the user the rules of the game
#have the computer guess a random number
#user tells if it is too (h)igh, (l)ow, or if it is (c)orrect
#if it is too low, generate a number above that, using the guess as low range
#if it is too high, generate a number below that, using the guess as high range
#keepGoing = false when correct.
#tell the user how many tries it took
#if it only took one guess change 'tries' to 'try' for grammatical purposes
import random
guess = 0
low = 0
high = 100
keepGoing = True
accuracy = ''
print ("Please think of a number between 1 and 100.")
print ("I'll guess your number.")
print ("You tell me if I'm too (h)igh, too (l)ow, or (c)orrect.")
while (keepGoing == True):
    attempt = random.randint(low,high)
    print ("My guess is ",attempt)
    invalid = True
    guess += 1
    while (invalid == True): 
        accuracy = input ("Too (h)igh, too (l)ow, or (c)orrect?")
        accuracy = str.lower(accuracy)
        if (accuracy == "c"):
            keepGoing = False
            invalid = False
        elif (accuracy == "l"):
            low = (attempt+1)
            invalid = False
        elif (accuracy == "h"):
            high = (attempt-1)
            invalid = False
        else:
            print ("I don't quite understand.")
if (guess == 1):
    print ("I got it! It took ", guess, "try.")
else:
    print ("I got it! It took ", guess, "tries.")
