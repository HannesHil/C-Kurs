#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>

void clean_stdin(void) {
    int c;
    do {
        c = getchar();
    } while (c != '\n' && c != EOF);
}

void darstellung(int Fehler, char * WortDarstell, char * gemachteChars) {
    printf("\n\n");
    if (Fehler >= 6) {
        printf("      ------\n");
    } else {
        printf("\n");
    }
    //next 1
    if (Fehler < 4) {
        printf("\n");
    } else if (Fehler == 4) {
        printf("      |\n");
    } else if (Fehler < 7) {
        printf("      |\n");
    } else if (Fehler >= 7) {
        printf("      |/   °\n");
    }
    //next 2
    if (Fehler < 4) {
        printf("");
    } else if (Fehler < 8) {
        printf("      |");
    } else if (Fehler < 9) {
        printf("      |    W");
    } else
        printf("      |   ^W^\t");
    if (Fehler > 10) {
        printf("Keine Leben mehr du bist TOT!");
    }
    if (Fehler == -1) {
        printf("Richtig :)");
    }
    printf("\n");
    //next 3
    if (Fehler < 4) {
        printf("\t\t");
    } else if (Fehler < 11) {
        printf("      |\t\t");
    } else {
        printf("      |   / \\\t");
    }
    printf("Wort: %s", WortDarstell);
    printf("\n");
    //next 4
    if (Fehler < 4) {
        printf("\t\t");
    } else {
        printf("      |\t\t");
    }
    printf("Falsch: %s", gemachteChars);
    printf("\n");
    //next 5
    if (Fehler < 3) {
        printf("");
    } else {
        printf("    -----");
    }
    printf("\n");
    //next 6
    if (Fehler < 1) {
        printf("");
    } else if (Fehler < 2) {
        printf("   /");
    } else {
        printf("   /     \\");
    }
    printf("\n");
    //next 7
    if (Fehler < 1) {
        printf("");
    } else if (Fehler < 2) {
        printf("  /");
    } else {
        printf("  /       \\");
    }
    printf("\n");
    //Next 8
    printf("==============\n\n");
}

void wortdarstellung(char * WortDarstellung, char * gerateneChars, char * zuSuchendesWort, int * gemachteFehler) {
    int i = 0;
    int lenght = strlen(WortDarstellung);
    int leereFelder = 0;
    while (i < lenght) {
        char temp = zuSuchendesWort[i];
        if (temp == ' ') {
            WortDarstellung[i] = ' ';
        } else if (strchr(gerateneChars, temp) == NULL) {
            WortDarstellung[i] = '-';
            leereFelder++;
        } else {
            WortDarstellung[i] = temp;
        }
        i++;
    }
    WortDarstellung[lenght] = '\0';
    if (leereFelder == 0) {
        *(gemachteFehler) = -1;
    }
}

void eingabe(int * gemachteFehler, char * geratendeChars, char * zuSuchendesWort, char * wortDarstellung) {
    printf("Bitte einen Char eingeben: ");
    char a = '0';
    char * ch = malloc(2);
    while (a == '0') {
        fgets(ch, 2, stdin);
        clean_stdin();
        if (ch[0] >= 97) {
            ch[0] -= 32;
        }
        if (ch[0] < 65 || ch[0] > 90) {
            printf("Bitte einen gueltigen Char eingeben: ");
        }
        if (strchr(geratendeChars, ch[0]) == NULL) {
            a = '1';
        } else {
            printf("Char schon eingegeben: ");
        }
    }
    strncat(geratendeChars, ch, 1);
    if (strchr(zuSuchendesWort, ch[0]) == NULL) {
        printf("Fehler char nicht im Wort enthalten!");
        (*gemachteFehler)++;
    } else {
        wortdarstellung(wortDarstellung, geratendeChars, zuSuchendesWort, gemachteFehler);
    }
}

int main() {
    int Fehler = 0;
    char * Wort;
    char * Gemachte;
    char * WortDarstell;
    char * Words[10];
    Gemachte = calloc(50, sizeof (char));
    Gemachte[0] = '\0';
    Words[0] = "TITANIC";
    Words[1] = "SCHIFFAHRTSGESELLSCHAFT";
    Words[2] = "COMPUTERABSTURZ";
    Words[3] = "VORSTANDSSPRECHER";
    Words[4] = "MAGAZIN";
    Words[5] = "KONTAKTANZEIGEN";
    Words[6] = "KOSTENPFLICHTIG";
    Words[7] = "KREDITKARTE";
    Words[8] = "EISENBAHN";
    Words[9] = "WIRRUNGEN";

    srand(time(NULL));
    Wort = Words[rand() % 10];
    WortDarstell = calloc(strlen(Wort), 1);
    int i = 0;
    for (i = 0; i < strlen(Wort); i++) {
        WortDarstell[i] = '-';
    }
    while (Fehler < 11 || Fehler == -1) {
        darstellung(Fehler, WortDarstell, Gemachte);
        eingabe(&Fehler, Gemachte, Wort, WortDarstell);
    }
    darstellung(Fehler, WortDarstell, Gemachte);
    return 1;
}
