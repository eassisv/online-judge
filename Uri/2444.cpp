#include <bits/stdc++.h>
using namespace std;

int main(void){
  int v, t;
  scanf("%d %d", &v, &t);
  vector <int> vs;
  for(int i = 0; i < t; i++){
    int a;
    scanf("%d", &a);
    if(v + a > 100) v = 100;
    else if(v + a < 0) v = 0;
    else v += a;
  }
  cout << v << endl;
  return 0;
}
