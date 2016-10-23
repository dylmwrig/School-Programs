"""
initialize Rectangle to set self.__height to height and same with width
getHeight simply returns height, same with width
area multiplies __height*__width, perimeter adds each multiplied by two
getStats is a multi-line print
"""
class Rectangle(object):
    
    def __init__(self, width = 10, height = 20):
        self.setWidth(width)
        self.setHeight(height)

    def setHeight (self, height):
        self.__height = height

    def setWidth (self, width):
        self.__width = width

    def getHeight (self):
        return self.__height

    def getWidth (self):
        return self.__width
    
    def area (self):
        area = (self.__height*self.__width)
        return area

    def perimeter (self):
        perimeter = ((2*self.__width)+(2*self.__height))
        return perimeter

    def getStats (self):
        print ("width: {}".format(self.__width))
        print ("height: {}".format(self.__height))
        print ("area: {}".format(self.area()))
        print ("perimeter: {}".format(self.perimeter()))
    

def main():
    print ("Rectangle a:")
    a = Rectangle(5, 7)
    print ("area:      {}".format(a.area()))
    print ("perimeter: {}".format(a.perimeter()))
    
    print ("")
    print ("Rectangle b:")
    b = Rectangle()
    b.width = 10
    b.height = 20
    print (b.getStats())

if __name__=="__main__":
    main()
