#include <bits/stdc++.h>
using namespace std;

#define MAX 112345

int main(void){
  int n, x, i;
  unsigned  m = 0, vs[MAX];
  scanf("%d", &n);
  for(i = 0; i < n; i++){
    scanf("%d", &x);
    vs[i] = x;
    m += x;
  }
	i--;
	sort(vs, vs+n);
	while(vs[i] >= (m - vs[i]) && i > 1){
		m -= vs[i];
		i--;
	}
  printf("%d\n", (i > 1)? i+1 : 0);
  return 0;
}
