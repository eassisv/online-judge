#include <stdio.h>
#include <string.h>

#define MAX 5123

int main(void){
  int N, i, j, ind, pos[55], size[55], aux;
  char s[MAX];

  scanf("%d", &N);
  getchar();
  while (N--){
    //Aqui nos vamos zerar nossos vetores
    memset(s, 0, sizeof(s));
    memset(size, 0, sizeof(size));
    //Aqui eu leio a string
    fgets(s, MAX, stdin);
    //Zerando as variaveis de controle, ind vai controlar a qtd de palavras
    //pos vai armazenar a posicao inicial de cada palavra
    //e size pega o tamanho de cada palavra
    ind = 0; pos[ind] = 0;  size[ind] = 0;
    //Aqui estou armazenar a posicao de cada palarva e seu tamanho
    for (i = 0; s[i] != '\n'; i++){
      if (s[i] != ' ')
        size[ind]++;
      else {
        pos[++ind] = i + 1;
        size[ind] = 0;
      }
    }
    //Aqui eu ordeno os vetores de posicao e de tamanho para ficarem
    //da maior palavra para a menor
    do{
      j = 0;
      for (i = 0; i <= ind; i++)
        if (size[i] < size[i+1]){
          aux = size[i];
          size[i] = size[i+1];
          size[i+1] = aux;
          aux = pos[i];
          pos[i] = pos[i+1];
          pos[i+1] = aux;
          j++;
        }
    }while(j);
    //no primeiro FOR estou printando todas as palavras menos a ultima
    //porque a ultima nao pode ter ESPAÇO ' ' depois dela
    //e depois no segundo for eu printo ela
    for (i = 0; i < ind; i++){
      j = pos[i];
      while(j < pos[i] + size [i] && s[j] != '\n')
        printf("%c", s[j++]);
      printf(" ");
    }
    for (i = pos[i]; i < pos[ind] + size [ind] && s[i] != '\n'; i++)
      printf("%c", s[i]);
    printf("\n");
  }
  return 0;
}
