#include <stdio.h>
#include <string.h>

int main(){
	char rev[1024];
	fgets(rev, 1024, stdin);
	int i;
	for( i = strlen(rev)-1; i >= 0;i--){
			printf("%c" ,  rev[i]);
	}
}
