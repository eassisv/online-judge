#include <stdio.h>
#include <deque>
using namespace std;

int main(void){
  int N, D, i;
  char c;
  deque<int> f;
  while(scanf("%d %d ", &N, &D), D && N){
    for(i = 1; i <= N; i++){
      scanf(" %c", &c);
      if(f.empty()) f.push_back(c - '0');
      else if(f.back() < (c-'0')){
	while(!f.empty() && D && f.back() < (c - '0')){
	  f.pop_back();
	  D--;
	}
	f.push_back(c - '0');
      }
      else
	f.push_back(c - '0');
    }
    while(D){
      D--;
      f.pop_back();
    }
    for(auto &x : f){
      printf("%d", x);
    }
    printf("\n");
    f.clear();
  }
  return 0;
}
