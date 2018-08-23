#include <stdio.h>
#include <math.h>

struct ponto{ int x, y; };

int C, N;
ponto bb;

int main(void){
  scanf("%d", &C);
  while(C--){
    scanf("%d", &N);
    int x, y, ans;
    double maior = 11235678.99, s;
    scanf("%d %d", &x, &y);
    bb.x = x; bb.y = y;
    for(int i = 1; i <= N; i++){
      scanf("%d %d", &x, &y);
      s = sqrt(pow(bb.x - x, 2) + pow(bb.y - y, 2));
      if((maior - s) > 0.01){
        maior = s;
        ans = i;
      }}
    printf("%d\n", ans);
  }
  return 0;
}
