#include <iostream>
#include <stdio.h>
#include <map>
#include <string>
using namespace std;

int main(void){
  int n, cont;
  double ans;
  string t;
  map <string, int> m;
  cin >> n; getchar();
  cont = 0;
  getchar();
  while(n){
    getline(cin, t);
    if(t.size()){
      m[t]++;
      cont++;
    }else{
      n--;
      for(auto &i: m){
        cout << i.first;
        ans = (double) i.second / cont * 100;
        printf(" %.4lf\n", ans);
      }
      m.clear();
      cont = 0;
      if(n) printf("\n");
    }}
  return 0;
}
