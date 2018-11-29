#include <cstdio>
#include <iostream>
#include <queue>
using namespace std;

void compress(char c, int n) {
  if(n <= 2) {
    char s = c == '$' ? ' ' : '0';
    while(n--) printf("%c", s);
  }else {
    for(int i = 0; i < n / 256; i++) printf("%c%c", c, 255);
    printf("%c%c", c, n % 255);
  }
}

int main(void) {
  char c;
  int ss = 0, zs = 0, n;
  deque<char> q;
  cin >> n;
  getchar();
  while(n--){
    for(;scanf("%c", &c) != EOF && c != '\n';) {
      if(c != ' ') {
        if(ss) compress('$', ss);
        ss = 0;
      }
      if(c != '0') {
        if(zs) compress('#', zs);
        zs = 0;
      }
      if(c == ' ') ++ss;
      else if(c == '0') ++zs;
      else printf("%c", c);
    }
    if(ss) compress('$', ss);
    if(zs) compress('#', zs);
    ss = zs = 0;
    puts("");
  }
  return 0;
}
