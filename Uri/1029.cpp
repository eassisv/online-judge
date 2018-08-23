#include <stdio.h>

int N, X, call;

int fib(int n){
	if(n == 0) return 0;
	if(n == 1) return 1;
	call += 2;
	return fib(n-1) + fib(n-2);
}

int main(void){
	scanf("%d", &N);
	for(int i = 0; i < N; i++){
		scanf("%d", &X);
		call = 0;
		printf("fib(%d) = %d calls = %d\n", X, call, fib(X));
	}
	return 0;
}
