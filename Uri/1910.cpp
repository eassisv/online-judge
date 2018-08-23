#include <stdio.h>
#include <string.h>
#include <queue>

using namespace std;

#define MAX 100001
#define INF 112345678

int O, D, K;
int dist[MAX*3];
bool p[MAX];

int op(int p, int i){
  if (i == 0) return p/2;
  if (i == 1) return p+1;
  if (i == 2) return p-1;
  if (i == 3) return p*2;
  return p*3;
}

int bfs(int orig, int dest){
  int i, x, y;
  queue<int> fila;

  for (i = 0; i <= MAX*2; i++)
    dist[i] = INF;

  dist[orig] = 0;
  fila.push(orig);

  while (!fila.empty()){
    x = fila.front();
    fila.pop();

    for (i = 0; i < 5; i++){
      if (x % 2 != 0 && !i)
        continue;
      y = op(x, i);
      if (y < MAX && !p[y]){
        if (y == dest) return dist[x] + 1;
        if (dist[y] == INF){
          dist[y] = dist[x] + 1;
          fila.push(y);
        }
      }
    }
  }
  return -1;
}

int main(void){
  int m, i;

  while (scanf("%d %d %d", &O, &D, &K), (O || D || K)){
    memset(p, 0, sizeof(p));
    for (i = 0; i < K; i++){
      scanf("%d", &m);
      p[m] = 1;
    }
    if (O == D) printf("0\n");
    else {
      m = bfs(O, D);
      printf("%d\n", m);
    }
  }
  return 0;
}
