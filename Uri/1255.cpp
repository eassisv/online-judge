#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX 212

int main(void){
  int N, maior, size, i, letras[26];
  char s[MAX], aux;

  scanf("%d", &N);
  getchar();
  while (N--){
    //primeiro eu limpo os vetores
    memset(s, 0, sizeof(s));
    memset(letras, 0, sizeof(letras));
    fgets(s, MAX, stdin);
    //Aqui eu pego o tamanho da string
    size = strlen(s) - 1;
    //e nesse primeiro 'for' eu verifico se e uma letra, se for eu conto ela no
    //vetor letras na posicao dela ex:('a'-'a'=0), ('b'-'a'=1), e assim
    //sucessivamente ate ('z'-'a'=26)
    for (i = 0; i < size; i++)
      if ((s[i] >= 'A' && s[i] <= 'Z') || (s[i] >= 'a' && s[i] <= 'z')){
        aux = tolower(s[i]);
        letras[aux - 'a']++;
      }
    //Nesse for vejo qual letra apareceu mais usando o valor de sua posicao no
    //vetor 'letras'
    for (maior = 0, i = 0; i < 26; i++)
      if(letras[i] > maior)
        maior = letras[i];
    //e nesse ultimo 'for' printo todas a letras com o valor igual da maior
    for (i = 0;  i < 26; i++)
      if (letras[i] == maior)
        printf("%c", i+'a');
    printf("\n");
  }

  return 0;
}
