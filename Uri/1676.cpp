#include <stdio.h>

#define MAX 3123
#define MAX_P 36234

int N, prim[MAX_P], sor[MAX];

void crivo(){
	int i, j, k, ind = 0;
	for(i = 2; ind < MAX; i++){
		if(prim[i]) continue;
		sor[ind++] = i;
		for(k = 0, j = i+1; j < MAX_P; j++){
			if(prim[j]) continue;
			else k++;
			if(k == i) {prim[j] = 1; k = 0;}
		}}}

int main(void){
	crivo();
	while(scanf("%d", &N), N){
		printf("%d\n", sor[N-1]);
	}
	return 0;
}