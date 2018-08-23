#include <stdio.h>
#include <stdlib.h>

#define MAX 21234

int T[MAX];

int cmp(const void* a, const void* b){
	return *(int*) a - *(int*) b;
}

int main(void){
	int n, m, flag, i, falsos;
	
	while(scanf("%d %d", &n, &m), n){
		for(i = 0; i < m; i++)
			scanf("%d", &T[i]);
		qsort(T, m, sizeof(int), &cmp);
		flag = falsos = 0;
		for(i = 0; i < m - 1; i++){
			if(T[i] == T[i + 1] && !flag){
				falsos++; flag = 1;
			}
			if(T[i] != T[i + 1])
				flag = 0;
		}
		printf("%d\n", falsos);
	}	
	return 0;
}
