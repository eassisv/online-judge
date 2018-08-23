#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_L 212
#define MAX_N 112345

struct lista{
	char num[MAX_L];
}tel[MAX_N];

int cmp(const void *a, const void *b){
	lista l1 = *(lista*)a, l2 = *(lista*)b;
	int i, len = (int) strlen(l1.num);
	for(i = 0; i < len; i++){
		if(l1.num[i] < l2.num[i]) return -1;
		else if(l1.num[i] > l2.num[i]) return 1;
	}
	return 0;
	
}

int main(void){
	int N, i, j, ini, fim, len, ans;
	char fila[MAX_L];
	while(scanf("%d ", &N) != EOF){
		for(i = 0; i < N; i++)
			scanf(" %s", tel[i].num);
		qsort(tel, N, sizeof(lista), &cmp);
		len = (int) strlen(tel[0].num);
		ini = fim = ans = 0;
		for(i = 0; i < len; i++)
			fila[fim++] = tel[0].num[i];
		for(j = 1; j < N; j++){
			ini = 0; fim = len;
			for(i = 0; i < len; i++){
				if(tel[j].num[i] == fila[ini++]){
					ans++;
				}else{
					ini -= 1;
					while(ini < fim){
						fila[ini] = tel[j].num[ini];
						ini++;
					}
					break;
				}}}
		printf("%d\n", ans);
	}
	return 0;
}
