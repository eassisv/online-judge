#include <bits/stdc++.h>
using namespace std;

int main(void){
  int a, b, c, ans = 0;
  scanf("%d %d %d", &a, &b, &c);
  if((a == b) || (a == c) || (a == (b + c))) ans = 1;
  if((b == c) || (b == (a + c))) ans = 1;
  if((c == (a + b))) ans = 1;
  printf("%c\n", ans ? 'S' : 'N');
  return 0;
}
