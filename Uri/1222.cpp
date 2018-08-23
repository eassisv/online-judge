#include <stdio.h>

int main(){
	int n, l, c;
	int letras, linhas, paginas;
	int i, p;
	char s;
	
	while (scanf("%d %d %d\n", &n, &l, &c) != EOF){
		letras = 0; linhas = 0; paginas = 1;
		for (i = 1; i <= n; i++){
			p = 0;
			while (scanf("%c", &s), s != ' ' && s != '\n'){
				p++;
			}
				letras += p;
				if (letras < c) {if(i < n) letras++;}
				if (letras == c && i < n) {linhas++; letras = 0;}
				if (letras > c) {linhas++;
					(i == n) ? letras = p : letras = p + 1;}
		}
			if (letras > 0) {linhas++; letras = 0;}
			while (linhas > 0){
			if (linhas > l)
				paginas++;
			linhas -= l;
			}
			printf("%d\n", paginas);
		}
	return 0;
}
