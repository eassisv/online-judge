#include <bits/stdc++.h>
using namespace std;

int main(void){
  int xm, ym, xr, yr;
  scanf("%d %d %d %d", &xm, &ym, &xr, &yr);
  printf("%d\n", (abs(xm - xr) + abs(ym - yr)));
  return 0;
}
