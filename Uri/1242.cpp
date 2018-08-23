#include <stdio.h>
#include <stack>
using namespace std;

int liga(char a, char b){
  if((a == 'S' && b == 'B') || (b == 'S' && a == 'B')) return 1;
  else if((a == 'C' && b == 'F') || (b == 'C' && a == 'F')) return 1;
  return 0;
}

int main(void){
  int ans;
  char c;
  stack <char> p;
  ans = 0;
  while(scanf("%c", &c) != EOF){
    if(c != '\n'){
      if(p.empty()) p.push(c);
      else {
        if(liga(p.top(), c)) {ans++; p.pop();}
        else p.push(c);
      }
    }else{
      while(!p.empty()) p.pop();
      printf("%d\n", ans);
      ans = 0;
    }
  }
  return 0;
}
