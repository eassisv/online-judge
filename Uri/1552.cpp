#include <bits/stdc++.h>
using namespace std;

#define MAX 512

struct ponto{ double x, y;
  ponto() {};
  ponto(double _x, double _y) : x(_x), y(_y) {};
};

typedef pair <double, int> di;

double adj[MAX][MAX];
ponto  cord[MAX];


double distancia(ponto a, ponto b){
  return sqrt(((a.x - b.x)*(a.x - b.x) + (a.y - b.y)*(a.y - b.y)));
}

double prim(int n){
  bool vis[MAX];
  for(int i = 0; i < n; i++) vis[i] = false;
  di u, v;
  double ans = 0;
  priority_queue <di> pq;
  pq.push(make_pair(0.00, 0));
  while(!pq.empty()){
    u = pq.top();
    pq.pop();
    if(vis[u.second]) continue;
    ans += (-u.first);
    vis[u.second] = true;
    for(int i = 0; i < n; i++){
      if(i != u.second && !vis[i]){
	v = make_pair(-adj[u.second][i], i);
	pq.push(v);
      }
    }
  }
  return ans;
}

int main(void){
  int c, n;
  scanf("%d", &c);
  while(c--){
    scanf("%d", &n);
    double x, y;
    for(int i = 0; i < n; i++){
      scanf("%lf %lf", &x, &y);
      cord[i] = ponto(x, y);
    }
    for(int i = 0; i < n; i++)
      for(int j = 0; j < n; j++)
	if(i == j){ adj[i][j] = 0; continue; }
	else adj[i][j] = adj[j][i] = distancia(cord[i], cord[j]);
    printf("%.2lf\n", prim(n)/100);
  }
  return 0;
}
