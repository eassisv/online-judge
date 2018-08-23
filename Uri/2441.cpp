#include <bits/stdc++.h>
using namespace std;

void ordena(int *a, int *b, int *c){
  if(*a > *b) swap(*a, *b);
  if(*b > *c) swap(*b, *c);
  if(*a > *b) swap(*a, *b);
}

int main(void){
  int f1, f2, f3, ans = 0;
  scanf("%d %d %d", &f1, &f2, &f3);
  ordena(&f1, &f2, &f3);
  ans += (f1 - 0) * 100 + (600 - (f3+200)) * 100;
  ans += (f1+200 < f2) ? (f2 - (f1+200)) * 100 : 0;
  ans += (f2+200 < f3) ? (f3 - (f2+200)) * 100 : 0;
  printf("%d\n", ans);
  return 0;
}
