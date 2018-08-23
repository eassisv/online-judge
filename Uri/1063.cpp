#include <stdio.h>

#define MAX 112

int main(void){
  int N, i, j, topo;
  char pilha[MAX], in[MAX], out[MAX];

  while(scanf("%d ", &N), N){
    for(i = 0; i < N; i++) scanf("%c ", &in[i]);
    for(i = 0; i < N; i++) scanf("%c ", &out[i]);
    for(i = j = topo = 0; i < N; i++){
      pilha[topo++] = in[i]; printf("I");
      while(topo){
      	if(pilha[topo - 1] != out[j]) break;
      	topo--; j++;
      	printf("R");
      }
    }
    if(!topo) printf("\n");
    else printf(" Impossible\n");
  }

  return 0;
}
