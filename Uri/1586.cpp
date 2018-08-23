#include <stdio.h>
#include <math.h>
#include <string.h>

#define MAX 112345

typedef long long int ll;

char nomes[MAX][15];
int valores[MAX];

ll calcula(int a, int n){
	long long int A = 0, B = 0;
	int mult;
	mult = 1;
	for(int i = a; i >= 0; i--)
		A += valores[i]*mult++;
	mult = 1;
	for(int i = a+1; i < n; i++)
		B += valores[i]*mult++;
	return A - B;
}
		
int buscabin(int n){
	int m, i = 0, f = n-1; 
	long long int s;
	m = (i+f)/2;
	s = calcula(m, n);
	if (s >= 0)
	while(m){
		if (s == 0) return m;
		else m--;
		s = calcula(m, n);
	}
	else
	while(m < n){
		if (s == 0) return m;
		else m++;
		s = calcula(m, n);
	}
	return -1;
}

int main(void){
	int N, i, j, pos;
	
	while (scanf("%d ", &N), N){
		memset(valores, 0, sizeof(valores));
		for (i = 0; i < N; i++) {
			scanf("%s", nomes[i]);
			for (j = 0; nomes[i][j] != '\0'; j++)
				valores[i] += nomes[i][j];
			}
		pos = buscabin(N);
		(pos != -1)? printf("%s\n", nomes[pos]) : printf("Impossibilidade de empate.\n");
	}	
	return 0;
}
