#include<stdio.h>
#include<string.h>

int main(void){
  int n, i;
  char jum[10], jdois[10], resultado[20];;

  scanf("%d", &n);
  for(i = 0; i < n; i++){
    scanf("%s %s", jum, jdois);
    if(strcmp(jum, jdois) == 0)
      switch(jum[1]){
      case 't': strcpy(resultado, "Aniquilacao mutua"); break;
      case 'e': strcpy(resultado, "Sem ganhador"); break;
      case 'a': strcpy(resultado, "Ambos venceram"); break;
      }
    else
      if((jum[1]=='t')||(jum[1]=='e' && jdois[1]=='a'))
	strcpy(resultado, "Jogador 1 venceu");
      else
	strcpy(resultado, "Jogador 2 venceu");

    printf("%s\n", resultado);
  }

  return 0;
}
