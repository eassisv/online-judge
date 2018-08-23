#include <stdio.h>
#include <algorithm>
using namespace std;

#define MAX 112

int N, pac, qtd[MAX], peso[MAX], memo[MAX][MAX];

int pd(){
  int i, j;
  for(i = 0; i <= pac; i++) memo[i][0] = 0;
  for(i = 0; i <= 50; i++) memo[0][i] = 0;
  for(i = 1; i <= pac; i++)
    for(j = 1; j < 51; j++)
      if(j >= peso[i])
	memo[i][j] = max(memo[i-1][j], memo[i-1][j-peso[i]] + qtd[i]);
      else
	memo[i][j] = memo[i-1][j];  
  return memo[pac][50];  
}

int main(void){
  scanf("%d", &N);
  int i, ans_qtd, ans_peso, ans_pac;
  while(N--){
    scanf("%d", &pac);
    for(i = 1; i <= pac; i++)
      scanf("%d %d", &qtd[i] ,&peso[i]);
    ans_qtd = pd();
    printf("%d brinquedos\n", ans_qtd);
    ans_peso = ans_pac = 0;
    int k;
    for(k = 50, i = pac; i > 0; i--)
      if(memo[i][k] != memo[i-1][k]){
	ans_pac++;
	ans_peso += peso[i];
	k -= peso[i];
      }
    printf("Peso: %d kg\n", ans_peso);
    printf("sobra(m) %d pacote(s)\n", pac - ans_pac);
    printf("\n");
  }
  return 0;
}
