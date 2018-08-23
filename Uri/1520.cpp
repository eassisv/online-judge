#include<stdio.h>
#include<stdlib.h>

#define MAX 11234

int v[MAX], Num;

int cmp(const void* a, const void* b){
  return *(int *) a - *(int *) b;
}
int buscabin(int i, int f){
  int m = 0;
    while(i < f){
      m = (i+f)/2;
      if(v[m] >= Num) f = m;
      else i = m + 1;
    }
  if(v[f] == Num) return f;
  else return -1;
}
int main(void) {
  int N, X, Y, i, j, ind, ind2;

  while(scanf("%d", &N) != EOF){
    j = 0;
    for(i = 0; i < N; i++){
      scanf("%d %d", &X, &Y);
      while(X <= Y){
	v[j] = X++;
	j++;
    }}
    scanf("%d", &Num);
    qsort(v, j, sizeof(int), &cmp);
    ind = ind2 = buscabin(0, j-1);   
    if(ind != -1){
      for(i = ind + 1; v[ind] ==  v[i]; i++)
	ind2++;
      printf("%d found from %d to %d\n", Num, ind, ind2);
    }else printf("%d not found\n", Num);
  }

  return 0;
}
