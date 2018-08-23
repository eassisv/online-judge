#include <stdio.h>

int main() {
	int i;
	double N, n[123];

	scanf("%lf", &N); n[0] = N;
	printf("N[%d] = %.4lf\n", 0, n[0]);
	for (i = 1; i < 100; i++){
		n[i] = n[i-1]/2.0;
		printf("N[%d] = %.4lf\n", i, n[i]);		
	}
	return 0;
}
