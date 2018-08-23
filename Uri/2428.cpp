#include <bits/stdc++.h>
using namespace std;

int main(void){
  int v[4];
  scanf("%d %d %d %d", &v[0], &v[1], &v[2], &v[3]);
  sort(v, v+4);
  printf("%c\n", (v[0] * v[3] == v[1] * v[2])? 'S' : 'N');
  return 0;
}
