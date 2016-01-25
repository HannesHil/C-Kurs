import sys

def printarray(Array):
    for row in Array:
        for a in row:
            sys.stdout.write(str(a))


a = [[1,2,3],[1,2,3]]
printarray((a*5))