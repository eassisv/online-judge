#include <stdio.h>
#include <string.h>

#define MAX 112

int p[MAX], rank[MAX], con;

void Make(int n){
  int i;
  for(i = 1; i <= n; i++) p[i] = i;
  memset(rank, 0, sizeof(rank));
}

int Find(int i){
  return (p[i] == i)? i : (p[i] = Find(p[i]));
}

void Union(int _x, int _y){
  int x = Find(_x), y = Find(_y);
  if(x != y){
    con--;
    if(rank[x] > rank[y]) p[y] = x;
    else{
      p[x] = y;
      if(rank[x] == rank[y]) rank[y]++;
    }
  }
}

int main(void){
  int t, n, m, a, b, i;

  scanf("%d", &t);
  for(i = 1; i <= t; i++){
    scanf("%d %d", &n, &m);
    con = n; Make(n);
    while(m--){
      scanf("%d %d", &a, &b);
      Union(a, b);
    }
    printf("Caso #%d: ", i);
    if(!(con-1)) printf("a promessa foi cumprida\n");
    else printf("ainda falta(m) %d estrada(s)\n", con-1);
  }
  
  return 0;
}
