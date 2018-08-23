#include <stdio.h>
#include <string.h>

#define MAX 112

int main(void){
  int N, size, i, j;
  char s[MAX], aux;

  scanf("%d", &N);
  getchar();
  while (N--){
    //Primeiro eu limpo o vetor de chars
    memset(s, 0, sizeof(s));
    fgets(s, MAX, stdin);
    //Agora eu descubro a ultima posicao do vetor que tem uma letra
    //tirando o \n e, e voltando mais uma pois a ultima posicao do
    //vetor de 8 e 8 - 1
    size = strlen(s) - 2;
    //Eu divido a string em duas e ordeno cada parte dentro de cada FOR
    //o primeiro FOR a primeira metade e no outro a segunda
    for (i = 0, j = size/2; i < j; i++, j--){
      aux = s[i];
      s[i] = s[j];
      s[j] = aux;
    }
    for (i = size/2+1, j = size; i < j; i++, j--){
      aux = s[i];
      s[i] = s[j];
      s[j] = aux;
    }
    //Aqui eu mostro a string ordenada
    printf("%s", s);
  }
  return 0;
}
