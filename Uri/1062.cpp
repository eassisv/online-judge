#include <stdio.h>

#define MAX 1123

int main(void){
  int N, i, j, ans;
  int out[MAX], pilha[MAX], topo;

  while(scanf("%d", &N), N){
    while(scanf("%d", &out[0])){
      if(!out[0]){ printf("\n"); break; }
      for(i = 1; i < N; i++){
      	scanf("%d", &out[i]);
      	if(!out[i]) break;
      }
      for(i = 1, j = ans = topo = 0; i <= N && !ans; i++){
      	pilha[topo++] = i;
      	while(pilha[topo - 1] == out[j]){
      	  j++; topo--;
      	  if(j == N) { ans = 1; break; }
      	  if(!topo) break;
	      }
      }
      printf("%s\n", (ans) ? "Yes": "No");
    }
  }
  return 0;
}
