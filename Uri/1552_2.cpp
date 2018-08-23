#include <bits/stdc++.h>
using namespace std;

#define MAX 512
typedef pair <int, int> ii;
typedef pair < double, ii > pi;

struct ponto{ double x, y; ponto() {}
	ponto(double _x, double _y) : x(_x), y(_y) {} };

int p[MAX], r[MAX];
pi v[MAX*MAX];
ponto pos[MAX];

void Make(int n){
	for(int i = 0; i < n; i++)
		p[i] = i;
}

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

double dist(ponto a, ponto b) { return sqrt((a.x - b.x)*(a.x - b.x) + (a.y - b.y)*(a.y - b.y)); }

double kruskal(int n){
	double ans = 0;
	for(int i = 0; i < n; i++)
		if(Union(v[i].second.first, v[i].second.second)) ans += v[i].first;
	return ans;
}

int main(void){
	int c, n, ind;
	scanf("%d", &c);
	while(c--){
		scanf("%d", &n);
		Make(n);
		double x, y;
		for(int i = 0; i < n; i++){
			scanf("%lf %lf", &x, &y);
			pos[i] = ponto(x, y);
		}
		ind = 0;
		for(int i = 0; i < n; i++)
			for(int j = 0; j < n; j++)
				if(i == j) continue;
				else v[ind++] = make_pair(dist(pos[i], pos[j]),make_pair(i, j));
		sort(v, v + ind);
		printf("%.2lf\n", kruskal(ind)/100);
	}
	return 0;
}