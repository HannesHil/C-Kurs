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

char * Words[10];
int Fehler = 0;
char * Wort;
char * Gemachte;
char * WortDarstell;

void darstellung() {
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
    printf("Falsch: %s", Gemachte);
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

void wortdarstellung(char * Worttemp, int lenght) {
    int i = 0;
    int leer = 0;
    while (i < lenght) {
        char temp = Wort[i];
        if (temp == ' ') {
            Worttemp[i] = ' ';
        } else if (strchr(Gemachte, temp) == NULL) {
            Worttemp[i] = '-';
            leer++;
        } else {
            Worttemp[i] = temp;
        }
        i++;
    }
    Worttemp[lenght] = '\0';
    if(leer == 0){
        Fehler = -1;
    }
}

void eingabe() {
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
        if (strchr(Gemachte, ch[0]) == NULL) {
            a = '1';
        } else {
            printf("Char schon eingegeben: ");
        }
    }
    strncat(Gemachte, ch, 1);
    if (strchr(Wort, ch[0]) == NULL) {
        printf("Fehler char nicht im Wort enthalten!");
        Fehler++;
    } else {
        wortdarstellung(WortDarstell, strlen(Wort));
    }
}

int main() {
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
    //    printf("%s\n", Wort);
    WortDarstell = calloc(strlen(Wort), 1);
    wortdarstellung(WortDarstell, strlen(Wort));
    //    printf("%s\n", WortDarstell);
    while (Fehler < 11|| Fehler == -1) {
        darstellung();
        eingabe();
    }
    darstellung();

    //HangmanDarstellung

    //Char eingeben
    //char schon vorhanden?
    //char
    return 1;
}
