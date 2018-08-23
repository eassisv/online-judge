#include <bits/stdc++.h>

#define MAX 112345

int cmp(const void *a, const void *b){
  return *(int *)a - *(int *)b;
}

int main(void){
  int t, s, c, r;
  int Ss[MAX];
  double ans;
  scanf("%d", &t);
  while(t--){
    scanf("%d %d %d", &s, &c, &r);
    for(int i = 0; i < s; i++)
      scanf("%d", &Ss[i]);
    qsort(Ss, s, sizeof(int), &cmp);
    ans = 0;
    for(int i = 0; i < c; i++)
      ans += ((double)1/(Ss[i]+r));
    for(int i = c; i < s; i++)
      ans += ((double)1/Ss[i]);
    printf("%.2lf\n", ans);
  }
  return 0;
}
