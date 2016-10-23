#ask for more money if not enough money is presented
#use a while loop and add additional inputs to the running tender, convert input as before
#define an array with each penny value of each cash demonination
#define an empty array to hold results
#define a counter for the arrays and while loop to use as a parameter, iterate at end of loop
#use a while loop to perform the function of the previous program, using each array rather than separate lines of code
#insert each result into the empty array
#output the results of the array as the amount of each cash value the user will get back
counter=0
print ("Welcome!")
total   = input ("What is the total of your purchase?")
tender  = input ("How much money did you give me?")
total   = float (total)
tender  = float (tender)
total   = int(round(total*100))
tender  = int(round(tender*100))
while (tender < total):
    print ("Not enough.")
    addition = input("Please give me more money.")
    addition = float (addition)
    addition = int(round(addition*100))
    tender += addition
change  = tender - total
divisions = [2000, 1000, 500, 100, 25, 10, 5, 1]
cash = [None] * 7
while (counter<=7):
    bills = int(change/divisions[counter])
    cash.insert(counter, bills)
    change = change%divisions[counter]
    counter+=1
print ("Twenties: ", cash[0])
print ("Tens: ", cash[1])
print ("Fives: ", cash[2])
print ("Ones: ", cash[3])
print ("Quarters: ", cash[4])
print ("Dimes: ", cash[5])
print ("Nickels: ", cash[6])
print ("Pennies: ", cash[7])
print ("Have a nice day!")

