import sys
import math

class complexnumber(object):

    def __init__(self,a,b):
        self.a = a
        self.b = b

    def add(self,newNumber):
        self.a += newNumber.a
        self.b += newNumber.b

    def betrag(self):
        return math.sqrt(math.pow(self.a,2)+math.pow(self.b,2))

    def __str__(self):
        return str(self.betrag())

if __name__ == '__main__':
    f = complexnumber(10,5)
    c = complexnumber(10,5)
    print(str(f.a))
    print(f)
    f.add(c)
    print(str(f.a))
    print(f)
    sys.exit(1)
