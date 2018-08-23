#include <iostream>
#include <string>
#include <ctype.h>
#include <map>
using namespace std;

int main(void){
  int m, n, vlr;
  string word;
  map <string, int> hp;
  cin >> m >> n;
  for(int i = 0; i < m; i++){
    cin >> word >> vlr;
    hp[word] = vlr;
  }
  vlr = 0;
  while(n){
    cin >> word;
    if(word[0] != '.')
      vlr += hp[word];
    else{
      cout << vlr << endl;
      vlr = 0;
      n--;
    }}
  return 0;
}
