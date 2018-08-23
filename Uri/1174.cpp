#include <stdio.h>

int main() {
	int i = 0;
	float n[150];
	
	while (i < 100){
		scanf("%f", &n[i]);
		if (n[i] <= 10)
		printf("A[%d] = %.1f\n", i,  n[i]);
		i++;
	}
	
	return 0;
}
