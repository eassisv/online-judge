#include <stdio.h>
#include <string.h>

#define MAX 1123

char s[MAX];

int main(){
	int N, i, ini, fim, open, close;

	scanf("%d", &N);
	getchar();
	while(N--){
		scanf("%s", s);
		getchar();
		printf("%s ", s);
		for(i = 0, ini = -1;ini == -1 && i < strlen(s); i++)
			if(s[i] == '<') ini = i;
		for(i = strlen(s) - 1, fim = -1; i >= ini && fim == -1; i--)
			if(s[i] == '>') fim = i;

		printf("ini = %d fim = %d ", ini, fim);
		if(ini == -1 || fim == -1){
			printf("0\n");
			continue;
		}
		open = close = 0;
		for(i = ini; i <= fim; i++){
			if(s[i] == '<') open++;
			if(s[i] == '>')	close++;
		}
		printf("%d\n", (open > close)? close: open);
		memset(s, 0, sizeof(s));
	}
	return 0;
}
