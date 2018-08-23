#include <bits/stdc++.h>
using namespace std;

struct ponto{ int x, y;
  ponto () {}
  ponto (int _x, int _y) : x(_x), y(_y) {};
};

ponto op(int i, ponto u){
  switch(i){
  case 0: return ponto(u.x+2, u.y+1);
  case 1: return ponto(u.x+2, u.y-1);
  case 2: return ponto(u.x-2, u.y+1);
  case 3: return ponto(u.x-2, u.y-1);
  case 4: return ponto(u.x+1, u.y+2);
  case 5: return ponto(u.x-1, u.y+2);
  case 6: return ponto(u.x+1, u.y-2);
  case 7: return ponto(u.x-1, u.y-2);
  default: return u;
  }
}

int bfs(ponto o, ponto d){
  int dist[9][9];
  for(int i = 0; i <= 8; i++)
    memset(dist[i], -1, sizeof(dist[i]));
  queue <ponto> q;
  dist[o.x][o.y] = 0;
  q.push(o);
  ponto u, v;
  while(!q.empty()){
    u = q.front();
    q.pop();
    if(u.x == d.x && u.y == d.y) break;
    for(int i = 0; i < 8; i++){
      v = op(i, u);
      if(v.x > 0 && v.x <= 8 && v.y > 0 && v.y <= 8)
	if(dist[v.x][v.y] == -1){
	  dist[v.x][v.y] = dist[u.x][u.y] + 1;
	  q.push(v);
	}}}
  return dist[d.x][d.y];
}

int main(void){
  ponto o, d;
  char s[11];
  while(fgets(s, 11, stdin)){
    o = ponto(s[1] - '0', s[0] - 'a'+1);
    d = ponto(s[4] - '0', s[3] - 'a'+1);
    printf("To get from %c%c to %c%c takes %d knight moves.\n",s[0], s[1], s[3], s[4], bfs(o, d));
  }
  return 0;
}
