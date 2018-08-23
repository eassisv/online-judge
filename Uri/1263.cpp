#include<stdio.h>
#include<string.h>
#include<ctype.h>

int main(void){
  int cont, i, j, n, aliteracao;
  char s[505], c[105];

  while(fgets(s, 505, stdin) != NULL){
    n = strlen(s) - 1;
    c[0] = toupper(s[0]);
    for(j = i = 1; i < n - 1; i++)
      if(s[i] == ' ')
	c[j++] = toupper(s[i+1]);
    aliteracao = cont = 0;
    for(i = 0; i < j - 1; i++)
      if(c[i] == c[i+1]){
	if(cont == 0){
	  aliteracao++;
	  cont = 1;
	}
      }
      else
	if(cont == 1)
	  cont = 0;

	
    printf("%d\n", aliteracao);
  }

  return 0;
}
