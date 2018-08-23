#include <bits/stdc++.h>
using namespace std;

int vogal(char c){
  switch(c){
  case 'a' : return 1;
  case 'e' : return 1;
  case 'i' : return 1;
  case 'o' : return 1;
  case 'u' : return 1;
  default : return 0;
  }
}

int main(void){
  char c, ans = 'S';
  deque <char> dq;
  while(scanf("%c", &c) != EOF){
    if(vogal(c))
      dq.push_back(c);
  }
  while(!dq.empty()){
    if(dq.front() != dq.back()){
      ans = 'N';
      break;
    }
    dq.pop_front();
    if(!dq.empty())
      dq.pop_back();
  }
  printf("%c\n", ans);
  return 0;
}
