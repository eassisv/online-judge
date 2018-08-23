#include<stdio.h>
#include<stdlib.h>

#define MAX 1123456

int N, Q; 
int v[MAX];

int cmp(const void *a, const void *b){
	return *(int *) a - *(int *) b;
}

int buscabin(int chave){
	int i = 0, f = N, m;
	while(i < f){
		m = (i + f)/ 2;
		if(v[m] >= chave) f = m;
		else if(v[m] < chave) i = m + 1;
	}
	return (v[i] == chave) ? i : -1;
}

int main(void){
	int i, casos = 1, resp;
	
	while (scanf("%d %d", &N, &Q), N){
		for (i = 0; i < N; i++) scanf("%d", &v[i]);
		qsort (v, N, sizeof(int), &cmp);
		printf("CASE# %d:\n", casos++);
		while(Q--){
			scanf("%d", &i);
			if((resp = buscabin(i)) != -1)
				printf("%d found at %d\n", i, resp + 1);
			else printf("%d not found\n", i);
		}
	}
	return 0;
}
