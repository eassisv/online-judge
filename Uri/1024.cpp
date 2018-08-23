#include <stdio.h>
#include <string.h>

#define MAX 1123

char s[MAX];

void criptografa(){
	int i, j;
	char aux;

	for (i = 0; s[i] != '\n'; i++)
		if ((s[i] >= 'a' || s[i] >= 'A') && (s[i] <= 'z' || s[i] <= 'Z'))
			s[i] += 3;
	i--;
	for (j = 0; j < i; i--, j++){
		aux = s[i];
		s[i] = s[j];
		s[j] = aux;
	}
	for (;s[j] != '\n'; j++)
		s[j] -= 1;
}

int main(void){
	int N;
	scanf("%d ", &N);
	while (N--){
      //Esse nao tem segredo leio a string e chamo a funcao criptografa
      //que faz exatamente o que o exercicio pede e na ordem que ele pede
      fgets(s, MAX, stdin);
      criptografa();
      printf("%s", s);
	}
	return 0;
}
