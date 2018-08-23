#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 61

typedef struct _camisa{
	char nome[MAX];
	char t;
	char cor[MAX];
}camisa;

int tam(char c){
	if(c == 'P') return 1;
	if(c == 'M') return 2;
	return 3;
}

int cmp(const void *a, const void *b){
	camisa c1, c2;
	c1 = *(camisa *)a;
	c2 = *(camisa *)b;
	if(c1.cor[0] < c2.cor[0]) return -1;
	if(c1.cor[0] > c2.cor[0]) return 1;
	if(tam(c1.t) < tam(c2.t)) return -1;
	if(tam(c1.t) > tam(c2.t)) return 1;	
	int i, l1 = (int)strlen(c1.nome), l2 = (int)strlen(c1.nome);
	for(i = 0; i < l1 && i < l2; i++){
		if(c1.nome[i] < c2.nome[i]) return -1;
		if(c1.nome[i] > c2.nome[i]) return 1;
	}
	if(l1 < l2) return -1;
	if(l1 > l2) return 1;
	return 0;
}

int main(void){
	int n = 0, i = 0;
	camisa c[MAX];
	while(scanf("%d", &n), n){
		getchar();
		if(i) printf("\n");
		for(i = 0; i < n; i++){
			fgets(c[i].nome, MAX, stdin);
			scanf("%s", c[i].cor);
			getchar();
			scanf("%c", &c[i].t);
			getchar();
		}
		qsort(c, n, sizeof(camisa), &cmp);
		for(i = 0; i < n; i++)
			printf("%s %c %s", c[i].cor, c[i].t, c[i].nome);	
	}
	return 0;
}
