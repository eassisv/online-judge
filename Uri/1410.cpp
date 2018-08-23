#include <stdio.h>

#define MAX 112345

int main(void){
	int A, D, B, C;
	int i, menorA, contD;
	
	while (scanf("%d %d", &A, &D), A){
		menorA = MAX; contD = 0;
		for (i = 0; i < A; i++){
			scanf("%d", &B);
			if(B < menorA)
				menorA = B;
		}
		for (i = 0; i < D; i++){
			scanf("%d", &C);
			if(C <= menorA)
				contD++;
		}
		(contD > 1) ? printf("N\n") : printf("Y\n");
	}	
	return 0;
}
