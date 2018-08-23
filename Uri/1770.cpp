#include <stdio.h>
#include <string.h>

#define MAX 112

int M, K, mus[MAX], ovd[MAX];

int main(void){
  int ans, n, flag, i, j;
  while(scanf("%d %d", &M, &K) != EOF){
    memset(ovd, 0, sizeof(ovd));
    for(i = 0; i < M; i++) scanf("%d", &mus[i]);
    for(i = flag = ans = 0; i < K; i++){
      scanf("%d", &n);
      if(!flag){
        if(!ovd[n-1]) ovd[n-1] = 1;
        ans += mus[n-1];
        for(j = 0, flag = 1; j < M; j++)
          if(!ovd[j]){ flag = 0; break; }
      }}
    printf("%d\n", (flag)? ans : -1);
  }
  return 0;
}
