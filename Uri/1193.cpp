#include <stdio.h>

int N;
char x[32], y[3];

int main(void){
	int caso, i;
	scanf("%d", &N);
	for(caso = 1; caso <= N; caso++){
		scanf("%s %s", x, y);
		printf("Case %d:\n", caso);
		switch(y[0]){
			case 'd':
				converteHexa(x);
			case 'h':

			case 'b':

		}
	}
	return 0;
}