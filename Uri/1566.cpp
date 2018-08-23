#include <stdio.h>

#define MAX 231

int altura[MAX];

int main(void){
	int NC, N, i, x, maior;

	scanf("%d", &NC);
	while(NC--){
		maior = 0;
		for(i = 20; i < MAX; i++)
			altura[i] = 0;
		scanf("%d", &N);
		for(i = 0; i < N; i++){
			scanf("%d", &x);
			altura[x]++;
			if(x > maior) maior = x;
		}
		for(i = 20; i < maior; i++)
			while(altura[i]--)
				printf("%d ", i);
		while(--altura[maior])
			printf("%d ", maior);
		printf("%d\n", maior);
	}
	return 0;
}
