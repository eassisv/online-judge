#include <stdio.h>

int main() {
	int n[10], i = 0;
	
	scanf("%d", &n[i]); printf("N[%d] = %d\n", i, n[i]);
	while (++i < 10){
		n[i] = n[i - 1] * 2;
		printf("N[%d] = %d\n", i,  n[i]);
	}
	
	return 0;
}
