#include <stdio.h>
#include <string.h>

#define MAX 5123

int x[MAX];

int busca(int a, int n){
	int i = a;
	int cont = 0;
	do{
		if(!x[i-1] && !x[i]) {cont++; x[i++] = 1;}
		else i++;
		if (i > n) {i = 1; x[0] = x[n];}
	}while (i != a);
	return cont;
}

int main(void){
	int N, i, flag, ini, ans;

	while (scanf("%d", &N), N){
		memset(x, 0, sizeof(x));
		for (flag = ini = i = 1; i <= N; i++){
			scanf("%d", &x[i]);
			if (x[i] && flag){
				ini = i; flag = 0;
			}
		}
		//printf("**%d**\n", ini);
		x[0] = x[N];
		ans = busca(ini, N);
		printf("%d\n", ans);
	} 
	return 0;
}
