#include <stdio.h>
#include <string.h>

#define MAX 112

typedef struct _crianca{
  char nome[50];
  int num;
}crianca;

int main(void){
  int n, i, num, ind, fim;
  crianca circ[MAX];
  int tbl[MAX];
  while(scanf("%d", &n), n){
    for(i = 0; i < n; i++)
      scanf(" %s %d", circ[i].nome, &circ[i].num);
    num = circ[0].num;
    ind = 0; fim = n;
    memset(tbl, 1, sizeof(tbl));
    while(fim > 1){
      for(i = 0; i < num; i++){
        if(num & 1){
            do{
              if(ind < n-1) ind++;
              else ind = 0;
            }while(!tbl[ind]);
        }else{
            do{
              if(ind > 0) ind--;
              else ind = n-1;
            }while(!tbl[ind]);
        }}
      tbl[ind] = 0;
      num = circ[ind].num;
      fim--;
    }
    for(i = 0; i < n; i++)
      if(tbl[i])
        printf("Vencedor(a): %s\n", circ[i].nome);
  }
  return 0;
}
