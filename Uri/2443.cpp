#include <bits/stdc++.h>
using namespace std;

int mdc(int a, int b){
  if (b == 0) return a;
  return mdc(b, a%b);
}

int main(void){
  int a, b, c, d;
  scanf("%d %d %d %d", &a, &b, &c, &d);
  int mdiv, num, den;
  den = b * d;
  num = den/b*a + den/d*c;
  mdiv = mdc(num, den);
  printf("%d %d\n", num/mdiv, den/mdiv);
  return 0;
}
