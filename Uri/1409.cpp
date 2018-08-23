#include <bits/stdc++.h>
using namespace std;

#define MAX 1123
#define INF 112345678
#define INF_D 2123456789123456789
#define f first
#define s second
typedef pair<int, int> ii;

vector <ii> mg(MAX), mt(MAX);
vector <int> adj[MAX], p(MAX);
int memo[MAX];


void pd(int m, int k){
  for(int i = 0; i <= k; i++) memo[i] = INF;
  for(int i = 1; i <= m; i++)
	for(int j = 1; j <= k; j++)
	  if(j <= mg[i].s)
		memo[j] = min(memo[j], mg[i].f);
	  else
		memo[j] = min(memo[j - mg[i].s] + mg[i].f, (int)(mg[i].f * ceil((double)j / mg[i].s)));
}

long long int dijkstra(int o, int d){
  long long dist[MAX];
  ii u, w;
  for(int i = 1; i <= d; i++) dist[i] = INF_D;
  priority_queue < ii, vector <ii>, greater<ii> > pq;
  u = make_pair(p[o], o);
  dist[o] = p[o];
  pq.push(u);
  while(!pq.empty()){
	u = pq.top();
	pq.pop();
	for(size_t i = 0; i < adj[u.s].size(); i++){
	  int x = adj[u.s][i];
	  if((dist[u.s] + p[x]) < dist[x]){
		dist[x] = dist[u.s] + p[x];
		w = make_pair(p[x], x);
		pq.push(w);
	  }
	}
  }
  return (dist[d] == INF_D) ? -1 : dist[d] ;
}

int main(void){
  int M, N, G, K;
  while(scanf("%d %d %d %d", &M, &N, &G, &K), M){
    for(int i = 1; i <= M; i++){
  	  int a, b;
  	  scanf("%d %d", &a, &b);
  	  mg[i] = make_pair(a, b);
    }
	sort(mg.begin(), mg.begin() + M);
    for(int i = 0; i < G; i++){
  	  int a, b;
  	  scanf("%d %d", &a, &b);
  	  adj[a].push_back(b);
  	  adj[b].push_back(a);
    }
	int m = 0;
	for(int i = 1; i <= K; i++){
	  int a, b;
	  scanf("%d %d", &a, &b);
	  if(b > m) m = b;
	  mt[i] = make_pair(a, b);
    }
	pd(M, m);
	for(int i = 1; i <= N; i++) p[i] = 0;
	for(int i = 1; i <= K; i++) p[mt[i].f] += memo[mt[i].s];
	printf("%lld\n", dijkstra(1, N));
    for(int i = 1; i <= N; i++) adj[i].clear();
  }
  return 0;
}
