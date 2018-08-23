#include <stdio.h>
#include <string.h>

#define MAX 55

int main(void){
  int n, i, j, size, ans;
  char s[MAX];

  while (scanf("%s %d", s, &n) != EOF){
    //Esse codigo nao tem muito segredo so verifico quantas vezes passei pelo
    //'R' e aumento o 'ans' quando o 'j' e igual a 0, quando nao e eu
    //eu verifico se ele e menor que 'n' e quando chega no valor 'n' eu zero
    // 'j', e quando passo pelo 'W', eu aumento 'ans' e zero 'j'
    size = strlen(s), ans = 0;
    for (i = 0, j = 0; i < size; i++)
      if (s[i] == 'R'){
        if (j > 0 && j < n) j++; else j = 0;
        if (!j){ ans++; j++; }
      }else{
        j = 0;
        ans++;
      }
    //aqui limpo meu vetor e printo o resultado
    memset(s, 0, sizeof(s));
    printf("%d\n", ans);
  }

  return 0;
}
