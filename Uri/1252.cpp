#include <stdio.h>
#include <stdlib.h>

#define MAX 11234

typedef struct _Nmod{
	int num, mod;
}Nmod;

int cmp(const void *a, const void *b){
	Nmod n1, n2;
	n1 = *(Nmod*)a; n2 = *(Nmod*)b;
	if(n1.mod != n2.mod) return n1.mod - n2.mod;
	if((n1.num & 1) && (n2.num & 1)) return n2.num - n1.num;
	if((n1.num & 1) || (n2.num & 1)) return (n1.num & 1)? -1: 1;
	return n1.num - n2.num;
}

int main(void){
	Nmod v[MAX];
	int N, M, i;
	while(scanf("%d %d", &N, &M), N || M){
		printf("%d %d\n", N, M);
		for(i = 0; i < N; i++){
			scanf("%d", &v[i].num);
			v[i].mod = v[i].num % M;
		}
		qsort(v, N, sizeof(Nmod), &cmp);
		for(i = 0; i < N; i++)
			printf("%d\n", v[i].num);
	}
	printf("%d %d\n", N, M);
	return 0;
}