#include <stdio.h>
#include <math.h>

int main(void){
	int a, b, q, r;
	
	scanf("%d %d", &a, &b);
	q = floor(((double) a / b) * (b > 0)) + ceil(((double) a / b) * (b < 0));
	r = a - b * q;
	printf("%d %d\n", q, r);

	return 0;
}
