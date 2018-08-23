#include <bits/stdc++.h>
using namespace std;

#define ull long long int
ull mt[2][2];


void mult_mt(ull m1[][2], ull m2[][2], int m){
  ull mta[2][2];
  mta[0][0] = ((m1[0][0] * m2[0][0]) % m + (m1[0][1] * m2[1][0]) % m ) % m;
  mta[0][1] = ((m1[0][0] * m2[0][1]) % m + (m1[0][1] * m2[1][1]) % m ) % m;
  mta[1][0] = ((m1[1][0] * m2[0][0]) % m + (m1[1][1] * m2[1][0]) % m ) % m;
  mta[1][1] = ((m1[1][0] * m2[0][1]) % m + (m1[1][1] * m2[1][1]) % m ) % m;
  for(int i = 0; i < 2; i++)
	for(int j = 0; j < 2; j++)
	  mt[i][j] = mta[i][j];
}

void calc_fib(ull n, int m){
  if(n == 1) return;
  calc_fib(n/2, m);
  mult_mt(mt, mt, m);
  if(n & 1){
	ull mt2[2][2] = {{1, 1}, {1, 0}};
	mult_mt(mt, mt2, m);
  }
}

ull fib(ull n, int m){
  if(n < 2) return n;
  calc_fib(n, m);
  return mt[1][0] % m;
}

void inicia_mt(){
  mt[0][0] = mt[0][1] = mt[1][0] = 1;
  mt[1][1] = 0;
}

int calc_mod(int m){
  int a = 0, b = 1, p = 2;
  do{
	int aux = (a + b) % m;
	a = b;
	b = aux;
	p++;
  }while(a != 0 || b != 1);
  return p - 2;
}

int main(void){
  ull n;
  int m;
  while(scanf("%lld %d", &n, &m) != EOF){
	inicia_mt();
	int p = calc_mod(m);
	int x = fib(n, p);
	inicia_mt();
	printf("%lld\n", fib(x, m));
  }
  return 0;
}
