#include <stdio.h>

int main() {
	int T, n[1123], i, j;

	scanf("%d", &T);
	for (i = 0; i < 1000;)
		for (j = 0; j < T; j++, i++)
			n[i] = j;
	for (i = 0; i < 1000; i++)
		printf("N[%d] = %d\n", i, n[i]);
	
	return 0;
}
