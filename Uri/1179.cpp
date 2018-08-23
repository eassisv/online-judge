#include <stdio.h>

int main() {
	int num, par[5], p = 0, impar[5], i = 0, j = 0;
	
		for (j = 0; j < 15; j++){
			scanf("%d", &num);
			if (num % 2 == 0)
				par[p++] = num;
			else 
				impar[i++] = num;
			if (p == 5){
				p = 0;
				while (p < 5){
				printf("par[%d] = %d\n", p, par[p]); p++; }
				p = 0;
			}
			if (i == 5){
				i = 0;
				while (i < 5){
				printf("impar[%d] = %d\n", i, impar[i]); i++;}
				i = 0;
			}
		}
		for (j = 0; j < i; j++)
			printf("impar[%d] = %d\n", j, impar[j]);
		for (j = 0; j < p; j++)
			printf("par[%d] = %d\n", j, par[j]);
		return 0;
}
