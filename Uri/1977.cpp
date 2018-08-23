#include <stdio.h>
#include <map>
#include <string>
#include <utility>
#include <queue>
#include <vector>
#include <iostream>

#define INF 112345678

using namespace std;

typedef pair < int, string > par;

int V, hr, mins;
map < string, vector<par> > mapa;
map < string, int > dist;
map < string, bool > vis;

int dijkstra(){
	int peso;
	string u, v;
	char origem[] = "varzea";
	char destino[] = "alto";
	priority_queue < par, vector<par>, greater<par> > Q;
	dist["varzea"] = 0;
	Q.push(par(dist[origem], origem));
	while(!Q.empty()){
		u = Q.top().second;
		Q.pop();
		if (vis[u] == true) continue;
		vis[u] = true;
		for(size_t i = 0; i < mapa[u].size(); i++){
			v = mapa[u][i].second;		
			peso = mapa[u][i].first;
			if(dist[u] + peso < dist[v]){
				dist[v] = dist[u] + peso;
				Q.push(par(dist[v], v));
			}
		}
	}
	return dist[destino];
}

int main(void){
	int X, N, i, T, ans = 0;
	string o, d;

	while(scanf("%d %d %d", &X, &N, &V), X){
		getchar();
		for(i = 0; i < N; i++){
			cin >> o >> d;
			getchar();
			cin >> T;
				mapa[o].push_back(par(T, d));
				dist[o] = INF;
				dist[d] = INF;
				vis[o] = false;
				vis[d] = false;
		}
		ans = dijkstra();
		mins = (X > 30)? 50 + ans: 30 + ans;
		hr = 17;
		while (mins >= 60){
			hr++;
			mins -= 60;
		}
		printf("%d:", hr);
		if(mins < 10) printf("0");
		printf("%d\n", mins);
		printf("%s\n", (hr > 17 && mins)? "Ira se atrasar":
			"Nao ira se atrasar");
		mapa.clear();
		vis.clear();
		dist.clear();
	}
	return 0;
}