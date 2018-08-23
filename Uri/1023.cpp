#include <stdio.h>
#include <string.h>

#define MAX 212

int main(void){
  int N, v[MAX], i, x, y, c, maior, m, pt, ct;
  double CM;
  c = 1;
  while(scanf("%d", &N), N){
    if(c > 1) printf("\n");
    maior = pt = ct = 0;
    memset(v, 0, sizeof(v));
    for(i = 1; i <= N; i++){
      scanf("%d %d", &y, &x);
      m = x/y; v[m] += y;
      pt += y; ct += x;
      if(m > maior) maior = m;
    }
    CM = (double)ct / pt - 0.00499999;
    printf("Cidade# %d:\n", c++);
    for(i = 0; i < MAX && i < maior; i++)
      if(v[i]) printf("%d-%d ", v[i], i);
    printf("%d-%d\nConsumo medio: %.2lf m3.\n", v[maior], maior, CM);
  }
  
  return 0;
}
