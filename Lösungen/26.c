#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void clean_stdin(void)
{
    int c;
    do {
        c = getchar();
    } while (c != '\n' && c != EOF);
}

int main(){
    int eingabe = 5;
    char * bufeingabe = (char *) calloc (eingabe, sizeof (char));
    char * bufbuf;
    char * end;
    int lange = 0;
    while(1){
		printf("Einen String eingeben : ");
        fgets(bufeingabe, eingabe , stdin);
        clean_stdin();
        int bufsize = strlen(bufeingabe);
        if(bufsize == 1){
            break;
        }
        if(bufeingabe[bufsize-1] == '\n'){
            bufeingabe[bufsize-1] = '\0';
            bufsize -= 1;
        }
        bufbuf = (char*)calloc(bufsize + lange + 1,sizeof(char));
        strncpy ( bufbuf , bufeingabe , bufsize);
        strncat(bufbuf, end,lange);
		lange += bufsize;
        free(end);
        end = (char *) calloc (lange,sizeof(char));
        strncpy ( end , bufbuf , lange ) ;
        free(bufbuf);
    }
    printf("%s\n", end);
    return 0;
}
