#include <stdio.h>

int main() {
	int N, T, i;
	long long int fib[112];
	
	fib[0] = 0; fib[1] = 1;
	for (i = 2; i < 61; i++)
		fib[i] = fib[i-1] + fib[i-2];
	
	scanf("%d", &T);
	for (i = 0; i < T; i++){
		scanf("%d", &N);
		printf("Fib(%d) = %lld\n", N, fib[N]);
	}
		
	return 0;
}
