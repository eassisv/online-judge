#include <stdio.h>
#include <queue>
#include <utility>
#include <vector>
#include <string.h>

using namespace std;

#define MAX 512	
#define INF 112345678

struct ponto{
	int x, y; ponto() {}
	ponto (int _x, int _y) : x(_x), y(_y) {}
};

typedef pair < int, int > ii;
typedef pair < int, ii > pi;

int n, m, dist[MAX][MAX];
char p[MAX][MAX], ok[MAX][MAX];
ponto inicio, fim;
int dx[] = {0, 0, -1, 1};
int dy[] = {-1, 1, 0, 0};

int dijkstra(){
	int i, j, peso;
	ponto u, v;
	for (i = 0; i < n; i++)
		for (j = 0; j < m; j++)
			dist[i][j] = INF;
	priority_queue < pi, vector < pi >, greater< pi > > Q;
	dist[inicio.x][inicio.y] = 0; Q.push(pi(0, ii(inicio.x, inicio.y)));
	memset (ok, 0, sizeof(ok));
	while (!Q.empty()){
		u = ponto(Q.top().second.first, Q.top().second.second);
		Q.pop();
		if(ok[u.x][u.y]) continue;
		ok[u.x][u.y] = 1;
		for(i = 0; i < 4; i++){
			v = ponto(u.x + dx[i], u.y + dy[i]);
			if (v.x < 0 || v.x >= n || v.y < 0 || v.y >= m ||
				p[v.x][v.y] == '#') continue;
			peso = (p[v.x][v.y] == '.' || p[v.x][v.y] == 'E')?
				0 : p[v.x][v.y] - '0';
			if (dist[u.x][u.y] + peso < dist[v.x][v.y]){
				dist[v.x][v.y] = dist[u.x][u.y] + peso;
				Q.push(pi(dist[v.x][v.y], ii(v.x, v.y)));
			}
		}
	}
	return dist[fim.x][fim.y];
} 

int main (void){
	int i, j, ans;
	
	scanf("%d %d ", &n, &m);
	for (i = 0; i < n; getchar(), i++)
		for (j = 0; j < m; j++){
			p[i][j] = getchar();
			if (p[i][j] == 'H')	inicio = ponto(i, j);
			if (p[i][j] == 'E') fim = ponto(i, j);
		}
	ans = dijkstra();
	(ans == INF) ? printf("ARTSKJID\n") : printf("%d\n", ans);	
	
	return 0;
}
