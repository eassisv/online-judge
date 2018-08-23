#include <stdio.h>
#include <vector>
using namespace std;

#define MAX 112

int main(void){
  int n, m, c;
  vector <int>  ht[MAX];
  scanf("%d", &n);
  while(n--){
    scanf("%d %d", &m, &c);
    int x;
    for(int i = 0; i < c; i++){
      scanf("%d", &x);
      ht[x % m].push_back(x);
    }
    for(int i = 0; i < m; i++){
      printf("%d -> ", i);
      for(auto j : ht[i]){
	printf("%d -> ", j);
      }
      printf("\\\n");
    }
    for(int i = 0; i < m; i++)
      ht[i].clear();
    if(n) printf("\n");
  }
  return 0;
}
