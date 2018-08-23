#include <stdio.h>

#define MAX 51

int N, L, v[MAX];

int bbsort(){
	int i, j, aux, ans, flag = 1;
	for(i = 0, ans = 0; flag != ans && i < L; i++){
		flag = ans;
		for(j = 0; j < L-1; j++){
			if(v[j] > v[j+1]){
				aux = v[j];
				v[j] = v[j+1];
				v[j+1] = aux;
				ans++;
			}}}
	return ans;
}

int main(void){
	int i;
	scanf("%d", &N);
	while(N--){
		scanf("%d", &L);
		for(i = 0; i < L; i++)
			scanf("%d", &v[i]);
		printf("Optimal train swapping takes %d swaps.\n", bbsort());
	}
	return 0;
}
