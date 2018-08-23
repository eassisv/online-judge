#include <stdio.h>
#include <iostream>
#include <list>
#include <string>
#include <map>
#include <ctype.h>
using namespace std;

int main(void){
  char c;
  string word;
  map <string, int> m;
  list <char> p;
  while(scanf("%c", &c) != EOF){
    if(isalpha(c)) p.push_back(tolower(c));
    else{
      while(!p.empty()){
        word += p.front();
        p.pop_front();
      }
      if(word.size()){
        m[word] = 1;
        word.erase();
      }
    }
  }
  for(auto &i : m)
    cout << i.first << endl;
  return 0;
}
