#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX 112

char s1[MAX], s2[MAX], c, ans[MAX];
int i, p1, p2, l1, l2;


int main(void){
	printf("cpf ");
	for(i = 0; i < 11;)	{ scanf("%c", &c); if(c >= '0' && c <= '9') { i ++; printf("%c", c); }} printf("\n");
	for(i = p1 = 0; p1 <= 2 && c != '\n';) {
		scanf("%c", &c);
		if((c >= '0' && c <= '9') || c == '.'){
			s1[i++] = c;

			if(p1) p1++; else if(c == '.') p1 = 1;
		}}
	while(c != '\n') scanf("%c", &c);
	for(i = p2 = 0, c = 0; p2 <= 2 && c != '\n';) {
		scanf("%c", &c);
		if((c >= '0' && c <= '9') || c == '.'){
			s2[i++] = c;
			if(p2) p2++; else if(c == '.') p2 = 1;
		}}
	s1[strlen(s1)] = '\0';
	long double ld1  = strtold(s1, NULL), ld2 = strtold(s2, NULL);
	printf("%.2Lf\n", (ld1 + ld2));
	return 0;
}
