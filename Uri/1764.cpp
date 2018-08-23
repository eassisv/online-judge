#include <bits/stdc++.h>
using namespace std;

#define MAX 41234
#define MAXV 51234
#define mp make_pair
typedef pair <int, int> ii;
typedef pair <int, ii> pii;

int p[MAX], r[MAX];

void Make(int n){ for(int i = 0; i < n; i++) { p[i] = i; r[i] = 0; }}

int Find(int i){ return (p[i] == i)? i : p[i] = Find(p[i]); }

bool Union(int _x, int _y){
	int x = Find(_x), y = Find(_y);
	if(x == y) return false;
	if(r[x] > r[y]) p[y] = x;
	else{
		p[x] = y;
		if(r[x] == r[y]) r[y]++;
	}
	return true;
}

int kruskal(int m, int n, pii vx[]){
	int ans = 0, cont = 1;
	sort(vx, vx+n);
	for(int i = 0; cont < m && i < n; i++)
		if(Union(vx[i].second.first, vx[i].second.second)){
			ans += vx[i].first; cont++;
		}
	return ans;
}

int main(void){
	int n, m;
	pii vx[MAXV];
	while(scanf("%d %d", &m, &n), m && n){
		Make(m);
		int a, b, x;
		for(int i = 0; i < n; i++){
			scanf("%d %d %d", &a, &b, &x);
			vx[i] = mp(x, mp(a, b));
		}
		printf("%d\n", kruskal(m, n, vx));
	}
	return 0;
}