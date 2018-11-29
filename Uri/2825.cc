#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

#define pb push_back

const int MAX = 1123;

vector<string> edda, vs;
vector<int> vlcs(MAX);
vector<vector<int>> mm(MAX, vector<int>(MAX)); 

int pd(string s1, string s2) {
  int l1 = s1.size(), l2 = s2.size();
  for(int i = 0; i <= max(l1, l2); i++) mm[i][0] = mm[0][i] = i;
  for(int i = 1; i <= l1; i++) {
    for(int j = 1; j <= l2; j++) {
      if(s1[i - 1] == s2[j - 1]) mm[i][j] = mm[i - 1][j - 1];
      else mm[i][j] = 1 +  min(mm[i - 1][j], min(mm[i - 1][j - 1], mm[i][j - 1]));
    }
  }
  return mm[l1][l2];
}

int main(void) {
  int N, C, m = 0;
  string s, ans;
  cin >> N;
  getchar();
  for(int i = 0; i < N; i++) {
    for(char c; scanf("%c", &c) != EOF && c != '\n'; s.pb(c));
    edda.pb(s);
    if((int)s.size() > m) m = s.size();
    s.clear();
  }
  cin >> C;
  getchar();
  for(int i = 0; i < C; i++) {
    for(char c; scanf("%c", &c) != EOF && c != '\n' && c != ' '; s.pb(c));
    int ans_t = m;
    for(auto j: edda) {
      int x = pd(s, j);
      if(x < ans_t) {
        ans = j;
        ans_t = x;
      }
    }
    s.clear();
    char c = i + 1 == C ? '\n' : ' ';
    cout << ans << c;
  }
  return 0;
}
