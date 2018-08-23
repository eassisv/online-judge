#include <stdio.h>
#include <string.h>

#define MAX 1123

int N;
int adj[MAX][MAX], tanq[MAX];

int dfs(int v, int t){
  if(tanq[v] != -1)
    return (tanq[v] == t);
  tanq[v] = t;
  for(int i = 0; i < N; i++)
    if(adj[v][i] == 0)
      if(!dfs(i, t ^ 1))
        return 0;
  return 1;
}

int main(void){
  scanf("%d", &N);
  int i, j;
  for(i = 0; i < N; i++)
    for(j = 0; j < N; j++)
      scanf("%d", &adj[i][j]);
  memset(tanq, -1, sizeof(tanq));
  for(i = 0; i < N; i++)
    if(tanq[i] == -1)
      if(!dfs(i, 0)){
        printf("Fail!\n");
        return 0;
      }
  printf("Bazinga!\n");
  return 0;
}
