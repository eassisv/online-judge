#include <stdio.h>

int main(void){
	int N, num, i, ans, cont;
	while(scanf("%d", &N), N){
		while(N--){
			for(i = cont = 0; i < 5; i++){
				scanf("%d", &num);
				if(num <= 127){
					cont++;
					ans = i;
				}}
		if(!cont || cont > 1) printf("*\n");
		else printf("%c\n", 'A'+ans);
		}}
	return 0;
}