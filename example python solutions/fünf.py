def numbers_to_strings(argument,Wert1,Wert2):
    switcher = {
        "*": "Mult "+ str(Wert1*Wert2),
        "multiply": "Mult "+ str(Wert1*Wert2),
        "+": "Summe "+ str(Wert1+Wert2),
        "add": "Summe "+ str(Wert1+Wert2),
        "-": "Dif "+ str(Wert1-Wert2),
    }
    return switcher.get(argument, "+")

if __name__ == '__main__':
    Wert1 = float(input("Bitte Wert eins eingeben: "))
    Wert2 = float(input("Bitte Wert eins eingeben: "))
    Oper = input("Bitte Operator eingeben: ")
    print((numbers_to_strings(Oper,Wert1,Wert2)))