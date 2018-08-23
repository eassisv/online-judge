#include <stdio.h>
#include <stdlib.h>

int mdc(int a, int b){
	if(b == 0) return a;
	return mdc(b, a % b);
}

int main(void){
	int N, N1, D1, N2, D2, num, den;
	char op;
	scanf("%d", &N);
	while(N--){
		scanf("%d / %d %c %d / %d", &N1, &D1, &op, &N2, &D2);
		switch(op){
			case '+':
				num = N1 * D2 + N2 * D1;
				den = D1 * D2;
				break;
			case '-':
				num = N1 * D2 - N2 * D1;
				den = D1 * D2;
				break;
			case '*':
				num = N1 * N2;
				den = D1 * D2;
				break;
			case '/':
				num = N1 * D2;
				den = D1 * N2;
				break;
		}
		printf("%d/%d = %d/%d\n", num, den,
			    num/mdc(abs(num), abs(den)),
			    den/mdc(abs(num), abs(den)));
	}
	return 0;
}