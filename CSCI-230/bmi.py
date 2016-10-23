"""
initialize each function within the bmi class:
ftHeight, inHeight, weight, button, calculate
the first three functions should hold the feet height, inch height, and weight respectively
define a button that, when clicked, calls the calculate function
when the calculate function is called, it multiplies the height by 12 and adds it to the inch height
the square of this value is divided by the weight which is multiplied by 703
display the body type
"""
from tkinter import *

class BMI (Tk):
    def __init__(self): #initializer
        Tk.__init__(self)
        self.title("Body Mass Index")
        self.ftHeight()
        self.inHeight()
        self.weight()
        self.button()
        self.calc()
        self.mainloop()
        
    def inHeight(self): #inches field
        Label(self, text = "in entry").grid(row = 0, column = 1)
        self.inEntry = Entry(self)
        self.inEntry.grid(row = 1, column = 1)
        self.inEntry.insert(0,"0")
        Label(self, text = "HT").grid(rowspan = 2, column = 3, row = 0) 

    def ftHeight(self): #feet field
        Label(self, text = "ft entry").grid(row = 0, column = 0)
        self.ftEntry = Entry(self)
        self.ftEntry.grid(row = 1, column = 0)
        self.ftEntry.insert(1,"1") #initialize value so we don't divide by zero
        
    def weight(self): #weight field
        Label(self, text = "weight entry").grid(columnspan = 2, row = 2, column  = 1)
        self.wtEntry = Entry(self)
        self.wtEntry.grid(columnspan = 2, row = 2, column = 1)
        self.wtEntry.insert(0,"0")
        Label(self, text = "WT").grid(rowspan = 2, column = 3, row = 2)

    def calc(self): #calculates the bmi
        heightFt = int(self.ftEntry.get())
        heightIn = int(self.inEntry.get())
        weight = int(self.wtEntry.get())

        height = (heightFt*12)+heightIn
        result = ((weight*703)/(height**2))

        if (result<18.5):
            status = "underweight"

        elif (result<=24.9):
            status = "normal"

        elif (result<=29.9):
            status = "overweight"

        else:
            status = "obese"

        Label(self, text = status).grid(row = 4, columnspan = 2)

    def button(self): #click this guy
        calculate = Button(self, text="Calculate", command=self.calc) #IMPORTANT NOTE if you set command to the function(), it will be called when the parameters are assigned. You must not include ()(because the function
        calculate.grid(row = 5, columnspan = 2)
        
def main():
    bmi = BMI()
    bmi.mainloop()

if __name__=="__main__":
    main()
