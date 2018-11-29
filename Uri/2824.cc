#include <bits/stdc++.h>
using namespace std;

#define MAX 5123

int mm[MAX][MAX];
char s1[MAX], s2[MAX];

int lcs(char *s1, char *s2) {
  int l1 = strlen(s1), l2 = strlen(s2);
  for(int i = 0, m = max(l1, l2); i <= m; i++) { mm[i][0] = mm[0][i] = 0; }
  for(int i = 1; i <= l2; i++) {
    for(int j = 1; j <= l1; j++) {
      if(s1[j - 1] == s2[i - 1])
        mm[i][j] = mm[i - 1][j - 1] + 1;
      else {
        mm[i][j] = max(mm[i - 1][j], mm[i][j - 1]);
      }
    }
  }
  return mm[l2][l1];
}

int main(void) {
  scanf("%s %s", s1, s2);
  printf("%d\n", lcs(s1, s2));
  return 0;
}
