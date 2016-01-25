sum = ""
while 1:
    eingabe = input("Bitte Ein Wort eingeben: ")
    if eingabe is "":
        break
    else:
        sum = eingabe+ sum

suche = input("Bitte das zu suchende Wort eingeben: ")
if suche in sum:
    print("Das zu suchende Wort ist enthalten")
else:
    print("Nicht enthalten")