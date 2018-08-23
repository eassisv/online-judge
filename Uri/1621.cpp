#include <stdio.h>
#include <string.h>
#include <queue>

using namespace std;

#define MAX 512

struct ponto { int x, y; ponto() {}
	ponto(int _x, int _y) : x(_x), y(_y) {} };

char m[MAX][MAX];
int N, M, dist[MAX][MAX];
int dx[] = {0, 0, 1, -1}, dy[] = {1, -1, 0, 0};

void bfs(ponto o){
	int i;
	ponto u = o, v;
	memset(dist, -1, sizeof(dist));
	queue <ponto> Q;
	dist[u.x][u.y] = 0;
	Q.push(u);
	while(!Q.empty()){
		u = Q.front(); Q.pop();
		for(i = 0; i < 4; i++){
			v = ponto(u.x + dx[i], u.y + dy[i]);
			if(v.x >= 0 && v.x < N && v.y >= 0 && v.y < M)
				if(m[v.x][v.y] == '.' && dist[v.x][v.y] == -1){
					dist[v.x][v.y] = dist[u.x][u.y] + 1;
					Q.push(v);
				}}}}

int main(void){
	int i, j, maior;
	while(scanf("%d %d ", &N, &M), N && M){
		ponto p(-1, -1);
		for(i = 0; i < N; i++)
			for(j = 0; j < M; j++){
				scanf(" %c", &m[i][j]);
				if(m[i][j] == '.' && p.x == -1){
					p = ponto(i, j);
				}}
		bfs(p);
		maior = 0;
		for(i = 0; i < N; i++)
			for(j = 0; j < M; j++)
				if(dist[i][j] > maior){
					maior = dist[i][j];
					p = ponto(i, j);
				}
		bfs(p);
		maior = 0;
		for(i = 0; i < N; i++)
			for(j = 0; j < M; j++)
				if(dist[i][j] > maior)
					maior = dist[i][j];				
		printf("%d\n", maior);
	}
	return 0;
}
