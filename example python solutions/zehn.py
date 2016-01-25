def add(Zahl1,Zahl2):
    return Zahl1 + Zahl2


def mult(Zahl1,Zahl2):
    return Zahl1 * Zahl2


def exp(Zahl1,Zahl2):
    if Zahl2 is 1:
        return Zahl1
    else:
        return Zahl1 * exp(Zahl1,Zahl2-1)

def numbers_to_strings(argument):
    switcher = {
        "*": mult,
        "multiply": mult,
        "+": add,
        "add": add,
        "exp": exp,
    }
    return switcher.get(argument, "+")

if __name__ == '__main__':
    Wert1 = float(input("Bitte Wert eins eingeben: "))
    Wert2 = float(input("Bitte Wert eins eingeben: "))
    Oper = input("Bitte Operator eingeben: ")
    print(str((numbers_to_strings(Oper)(Wert1,Wert2))))
