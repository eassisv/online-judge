#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int cmp(const void *a, const void *b){
	return *(char*) a - *(char*) b;
}

int main(void) {
	int i = 0, len;
	char s[100], c1, c2;
		
	memset(s, 0, sizeof(s));
	while (fgets(s, 100, stdin) != NULL){
		len = strlen(s) - 1;
		if(!len){
			printf("\n");
			continue;
		}
		qsort(s, len, sizeof(char), &cmp);
		for(i = 0; i < len; i++) if(s[i] != ' ') break;
		for(c1 = c2 = s[i]; i < len; i++){
			if(s[i] == c2 || s[i] == c2 + 1) c2 = s[i];
			else{
				printf("%c:%c, ", c1, c2);
				c1 = c2 = s[i];
			}
		}	
		printf("%c:%c\n", c1, c2);
	}
	return 0;
}
