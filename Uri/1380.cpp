#include <bits/stdc++.h>
using namespace std;

#define MAX 1123456

queue <int> n;

int periodo(){
  int a = 0, b = 1, p = 0;
  do{
	int n = (a + b) % 1000;
	a = b;
	b = n;
	p++;
  }while(a != 0 || b != 1);
  return p;
}

int divisao(int p){
  int x = 0;
  while(!n.empty()){
	x += n.front() - '0';
	n.pop();
	if(x < p && !n.empty()){ x *= 10; continue; }
	x %= p;
	if(!n.empty()) x *= 10;
  }
  return x;
}

void mult(int m1[][2], int m2[][2], int m){
  int mta[2][2];
  mta[0][0] = ((m1[0][0] * m2[0][0]) % m + (m1[0][1] * m2[1][0]) % m ) % m;
  mta[0][1] = ((m1[0][0] * m2[0][1]) % m + (m1[0][1] * m2[1][1]) % m ) % m;
  mta[1][0] = ((m1[1][0] * m2[0][0]) % m + (m1[1][1] * m2[1][0]) % m ) % m;
  mta[1][1] = ((m1[1][0] * m2[0][1]) % m + (m1[1][1] * m2[1][1]) % m ) % m;
  for(int i = 0; i < 2; i++)
	for(int j = 0; j < 2; j++)
	  m1[i][j] = mta[i][j];
}

void calc_fib(int n, int m, int mt[][2]){
  if(n == 1) return;
  calc_fib(n / 2, m, mt);
  mult(mt, mt, m);
  if(n & 1){
	int mt2[2][2];
	mt2[0][0] = mt2[0][1] = mt2[1][0] = 1;
	mt2[1][1] = 0;
	mult(mt, mt2, m);
  }
}

int fib(int n, int m){
  if(n < 2) return n;
  int mt[2][2];
  mt[0][0] = mt[0][1] = mt[1][0] = 1;
  mt[1][1] = 0;
  calc_fib(n, m, mt);
  return mt[0][1];
}

int main(void){
  char c;
  int t, p;
  p = periodo();
  scanf("%d", &t);
  getchar();
  while(t--){
	while(scanf("%c", &c) && c != '\n') n.push(c);
	int x = divisao(p);
	printf("%03d\n", fib(x, 1000));
  }
  return 0;
}
