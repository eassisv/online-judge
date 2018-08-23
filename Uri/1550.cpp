#include <stdio.h>
#include <queue>

using namespace std;

#define MAX 11234
#define INF 112345678

int A, B, dist[MAX];

int inverte(int v){
	int ans = 0 ,aux ,i = 10;
	while(i <= v){
		aux = (v % i);
		ans = ((ans * 10) + (aux / (i/10)));
		i *= 10;
	}
	i /= 10;
	aux = (v / i);
	ans = (ans * 10) + aux	;

	return ans;
}

int op(int i, int v){
	if(!i) return inverte(v);
	return v + 1;
}

int bfs(){
	int i, u, v;
	for(i = 0; i < MAX; i++)
		dist[i] = INF;
	queue <int> Q;
	dist[A] = 0;
	Q.push(A);
	while(!Q.empty()){
		u = Q.front();
		Q.pop();
		for(i = 0; i < 2; i++){
			v = op(i, u);
			if(v < MAX){
				if(v == B) return dist[u] + 1;
				if(dist[v] == INF){
					dist[v] = dist[u] + 1;
					Q.push(v);
				}
			}
		}
	}
	return -1;
}

int main(void){
	int T, ans;
	
	scanf("%d", &T);
	while(T--){
		scanf("%d %d", &A, &B);
		ans = bfs();
		printf("%d\n", ans);
	}
	return 0;
}
