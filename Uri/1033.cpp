#include <bits/stdc++.h>
using namespace std;

#define ull long long int

ull mt[3][3];

void mult_mt(ull mt[][3], ull mt2[][3], int m){
  ull auxmt[3][3] = {{0, 0, 0}, {0, 0, 0}, {0, 0, 1}};

  auxmt[0][0] = ((mt[0][0] * mt2[0][0])%m + (mt[0][1] * mt2[1][0])%m + (mt[0][2] * mt2[2][0])%m)%m;
  auxmt[0][1] = ((mt[0][0] * mt2[0][1])%m + (mt[0][1] * mt2[1][1])%m + (mt[0][2] * mt2[2][1])%m)%m;
  auxmt[0][2] = ((mt[0][0] * mt2[0][2])%m + (mt[0][1] * mt2[1][2])%m + (mt[0][2] * mt2[2][2])%m)%m;

  auxmt[1][0] = ((mt[1][0] * mt2[0][0])%m + (mt[1][1] * mt2[1][0])%m + (mt[1][2] * mt2[2][0])%m)%m;
  auxmt[1][1] = ((mt[1][0] * mt2[0][1])%m + (mt[1][1] * mt2[1][1])%m + (mt[1][2] * mt2[2][1])%m)%m;
  auxmt[1][2] = ((mt[1][0] * mt2[0][2])%m + (mt[1][1] * mt2[1][2])%m + (mt[1][2] * mt2[2][2])%m)%m;

  for(int i = 0; i < 3; i++)
	for(int j = 0; j < 3; j++)
	  mt[i][j] = auxmt[i][j];
}

void calc_fib(ull n, int m){
  if(!n || n == 1) return;

  calc_fib(n / 2, m);

  mult_mt(mt, mt, m);

  if(n & 1){
	ull mt2[3][3] = {{1, 1, 1}, {1, 0, 0}, {0, 0, 1}};
	mult_mt(mt, mt2, m);
  }

}

int fib(ull n, int m){
  calc_fib(n, m);
  return (mt[1][0] + mt[1][1] + mt[1][2])%m;
}

void inicia_mt(){
  ull auxmt[3][3] = {{1, 1, 1}, {1, 0, 0}, {0, 0, 1}};

  for(int i = 0; i < 3; i++)
	for(int j = 0; j < 3; j++)
	  mt[i][j] = auxmt[i][j];
}

int main(void){
  ull n;
  int m, caso = 1;

  while(scanf("%lld %d", &n, &m), n || m){
	inicia_mt();
	printf("Case %d: %lld %d %d\n", caso++, n, m, fib(n, m));
  }

  return 0;
}
