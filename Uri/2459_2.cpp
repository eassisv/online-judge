#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define ft first
#define sd second
#define mp make_pair
#define MAX 112

typedef pair <int , int> ii;
typedef pair < ii , ii > pii;

int p[MAX], r[MAX];

void Make(int n){
	for(int i = 1; i <= n; i++) p[i] = i;
}

int Find(int i) { return (p[i] == i)? i : p[i] = Find(p[i]); }

bool Union(int _x, int _y){
	int x = Find(_x), y =  Find(_y);
	if(x == y) return false;
	if(r[x] > r[y]) p[y] = x;
	else{
		p[x] = y;
		if(r[x] == r[y]) r[y]++;
	}
	return true;
}

int kruskal(int n,vector <pii> &vx){
	sort(vx.begin(), vx.end());
	int ans = 0, cont = 0;
	for(int i = 0; i < (int)vx.size() && cont < n-1; i++)
		if(Union(vx[i].sd.ft, vx[i].sd.sd)){
			ans += vx[i].ft.sd;
			cont ++;
		} 
	return ans;
}

int main(void){
	int n, f, r, i;
	scanf("%d %d %d", &n, &f, &r);
	vector <pii> vx (f+r);
	int a, b, c;
	Make(n);
	for(i = 0; i < f; i++){
		scanf("%d %d %d", &a, &b, &c);
		vx[i] = mp( mp(1, c), mp(a, b) );
	}
	for(; i < f+r; i++){
		scanf("%d %d %d", &a, &b, &c);
		vx[i] = mp( mp(2, c), mp(a, b));
	}
	//for(auto i : vx) cout << i.ft.sd << endl;
	printf("%d\n", kruskal(n, vx));
	return 0;
}