#include <stdio.h>

#define MAX 1123

int main(void){
  int C, N, nt[MAX], total;
  double media, ans;
  scanf("%d", &C);
  while(C--){
    scanf("%d", &N);
    total = 0;
    for(int i = 0; i < N; i++){
      scanf("%d", &nt[i]);
      total += nt[i];
    }
    media = (double) total / N;
    total = 0;
    for(int i = 0; i < N; i++){
      if(nt[i] - media > 0.000000)
        total++;
    }
    ans = (double)total / N * 100.00;
    printf("%.3lf%\n", ans);
  }
  return 0;
}
