#include <bits/stdc++.h>
using namespace std;

#define MAX 11234

int p[MAX], r[MAX];

void Make(int n){
	for(int i = 1; i <= n; i++) { p[i] = i; r[i] = 0; }
}

int Find(int i) { 
	int v = i;
	while(p[v] != v){	v = p[v];	}
	return p[i] = v;
}

int Union(int a, int b){
	int x = Find(a), y = Find(b);
	if(x == y) return 0;
	if(r[x] > r[y]) p[y] = x;
	else{
		p[x] = y;
		if(r[x] == r[y]) r[y]++;
	}
	return 1;
}

int main(void){
	int n, m, ans;
	while(scanf("%d %d", &n, &m) != EOF){
		Make(n);
		int a, b;
		ans = 1;
		for(int i = 0; i < m; i++){
			scanf("%d %d", &a, &b);
			if(ans) ans = Union(a, b);
		}
		printf("%s\n", ans ? "Seguro" : "Inseguro");
	}
	return 0;
}