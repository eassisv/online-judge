#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;

#define MAX 212

int qds[MAX][MAX];

int max_size_submatrix(int n, int m){
  int maximum = 0, table[MAX][MAX];
  for(int i = 0; i < n; ++i) table[0][i] = 0;
  for(int i = 0; i < m; ++i) table[i][0] = 0;
  for(int i = 0; i < n; ++i)
    for(int j = 0; j < m; ++j){
      if(!qds[i][j]) table[i + 1][j + 1] = 0;
      else{
	int a = min(table[i + 1][j], table[i][j]);
	a = min(a, table[i][j + 1]);
	table[i + 1][j + 1] = a + 1;
	if(a + 1 > maximum) maximum = a + 1;
      }
    }
  return maximum;
}

int main(void){
  int n, m, q;
  cin >> n >> m;
  for(int i = 0; i < n; i++)
    for(int j = 0; j < m; j++)
      scanf("%d", qds[i] + j);
  int maximum = max_size_submatrix(n, m);
  cin >> q;
  while(q--){
    int s;
    scanf("%d", &s);
    printf("%s\n", (s > maximum) ? "no" : "yes");
  }
  return 0;
}
