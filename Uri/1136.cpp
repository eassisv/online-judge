#include<stdio.h>
#include<stdlib.h>

using namespace std;

int main(void){
  int i, j, n, n2, b, bi[100], aux, verifica;

  while(scanf("%d %d", &n, &b), n){
    for(i = 0; i < b; i++)
      scanf("%d", &bi[i]);
    
    for(i = 0; i < b; i++)    
      for(j = b-1; j > 0 ; j--)
	if(bi[j] < bi[j-1]){	
	   aux = bi[j];
	   bi[j] = bi[j-1];
	   bi[j-1] = aux;
	}

    verifica = 0;
    aux = 0;
    n2 = n;
    while(n2 >= 0){
      bi[99] = 1;
      for(i = 0; bi[99] && i < b; i++){
	for(j = 0;bi[99] && j < b; j++)
	  if(abs(bi[i] - bi[j]) == aux){
	    verifica++;
	    bi[99] = 0;	    
	  }
      }
      aux++;
      n2--;
    }
    if(verifica == n+1) printf("Y\n");
    else printf("N\n");
  }
  return 0;
}
