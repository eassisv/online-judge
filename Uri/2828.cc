#include<cstdio>
#include<iostream>
#include<vector>
using namespace std;

typedef vector<int64_t> vi;

const int64_t mod = 1e9+7;
vi map('z' - 'a' + 1, 0);
vi fact(2, 1);

int64_t expbin(int64_t a, int64_t exp) {
  if(!exp) return 1L;
  return expbin(a * a % mod, exp / 2) * (exp & 1 ? a : 1) % mod;
}

int main(void) {
  int64_t num = 0, den = 1;
  for(char c; scanf("%c", &c) != EOF && c != '\n'; map[c - 'a']++, num++);
  fact.resize(num + 1);
  for(int i = 2; i <= num; i++) {
    fact[i] = fact[i - 1] * i % mod;
  }
  for(int64_t i: map) {
    if(i > 1) {
      den = den * fact[i] % mod;
    }
  }
  int64_t ans = fact[num] * expbin(den, mod - 2) % mod;
  cout << ans << "\n";
  return 0;
}
