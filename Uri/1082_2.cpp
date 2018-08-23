#include <bits/stdc++.h>
using namespace std;

int cc[31], p[31], r[31], ans;

void Make(int n){
  for(int i = 0; i < n; i++){
    p[i] = i;
    r[i] = 0;
    cc[i] = -1;
  }
}

int Find(int i){
  return (p[i] == i)? i : (p[i] = Find(p[i]));
}

void Union(int _x, int _y){
  int x = Find(_x), y = Find(_y);
  if(x != y){
    ans--;
    if(r[x] > r[y]) p[y] = x;
    else{
      p[x] = y;
      if(r[x] == r[y]) r[y]++;
    }
  }
}

int main(void){
  int n, v, e;
  char a, b;
  scanf("%d", &n);
  for(int i = 1; i <= n; i++){
    scanf("%d %d", &v, &e);
    Make(v); ans = v;
    for(int j = 0; j < e; j++){
      scanf(" %c %c", &a, &b);
      Union(a-'a', b-'a');
    }
    printf("Case #%d:\n", i);
    for(int j = 0; j < v; j++){
      if(cc[j] == -1){
      	a = Find(j)+'a';
      	for(int k = j; k < v; k++){
      	  b = Find(k)+'a';
      	  if(a == b){
      	    printf("%c,", k+'a');
      	    cc[k] = a;
	        }
        }
	      printf("\n");
      }
    }
    printf("%d connected components\n\n", ans);
  }
  return 0;
}
