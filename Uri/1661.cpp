#include <bits/stdc++.h>
using namespace std;

#define MAX 112345

typedef pair<int, int> cs;

int main(void){
  int n;
  while(scanf("%d", &n), n){
    deque <cs> vs, clis; 
    for(int i = 0; i < n; i++){
      int x;
      scanf("%d", &x);
      if(x >= 0) clis.push_back(make_pair(x, i));
      else vs.push_back(make_pair(x, i));
    }
    long long ans = 0;
    for(auto i : clis){
      while(i.first){
	if(i.first >= abs(vs.front().first)){
	  ans += abs(vs.front().first * abs(i.second - vs.front().second));
	  i.first += vs.front().first;
	  vs.pop_front();
	}
	else{
	  ans += abs(i.first * abs(i.second - vs.front().second));
	  vs.front().first += i.first;
	  i.first = 0;
	}
      }
    }
    printf("%lld\n", ans);
  }
    return 0;
}
