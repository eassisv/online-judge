#include <bits/stdc++.h>
using namespace std;

#define ull unsigned long long

int main(void){
  ull r, g, b, tg, tb;

  scanf("%llx %llx %llx", &r, &g, &b);
  b = (g / b);
  g = (r / g);
  tg = g * g;
  tb = tg * b * b;
  printf("%llx\n", 1 + tg + tb);
  
  return 0;
}
