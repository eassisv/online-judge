#include <cstdio>
#include <iostream>
#include <vector>
using namespace std;

#define PAI(x) (x >> 1)
#define LEFT(x) (x << 1)
#define RIGHT(x) (x << 1 | 1)
#define vi vector<int>
#define MAX 112345

struct Node{
  int min, max;
  Node() {}
  Node(int x, int y) : min(x), max(y) {}
  int dif(int ns[]){
    return ns[max] - ns[min];
  }
};

Node getMinMax(int ns[], Node a, Node b){
  int min, max;
  if(a.min == -1) return b;
  else if(b.min == -1) return a;
  min = ns[a.min] < ns[b.min] ? a.min : b.min;
  max = ns[a.max] > ns[b.max] ? a.max : b.max;
  return Node(min, max);
}

void build(int ns[], Node st[], int i, int l, int r) {
  if(l == r) { st[i] = Node(l, l); return; }
  int mid = (l + r) / 2;
  build(ns, st, LEFT(i), l, mid);
  build(ns, st, RIGHT(i), mid + 1, r);
  st[i] = getMinMax(ns, st[LEFT(i)], st[RIGHT(i)]);
}

void update(int ns[], Node st[], int i, int l, int r, int ind, int vlr){
  if(l == r) {
    ns[ind] = vlr;
    st[i] = Node(ind, ind);
    return;
  }
  int mid = (l + r) / 2;
  if(l <= ind && ind <= mid) update(ns, st, LEFT(i), l, mid, ind, vlr);
  else update(ns, st, RIGHT(i), mid + 1, r, ind, vlr);
  st[i] = getMinMax(ns, st[LEFT(i)], st[RIGHT(i)]);
}

Node query(int ns[], Node st[], int ind, int l, int r, int i, int j){
  if(l > j || r < i) return Node(-1, -1);
  if(l >= i && j >= r) return st[ind];
  int mid = (l + r) / 2;
  Node n1 = query(ns, st, LEFT(ind), l, mid, i, j);
  Node n2 = query(ns, st, RIGHT(ind), mid + 1, r, i, j);
  return getMinMax(ns, n1, n2);
}

int main(void){
  int N, Q, ns[MAX];
  Node st[4*MAX+1];
  while(scanf("%d", &N) != EOF){
    for(int i = 0; i < N; i++){
      scanf("%d", ns + i); 
    }
    build(ns, st, 1, 0, N-1);
    cin >> Q;
    for(int i = 0, x, l, r; i < Q; i++){
      scanf("%d %d %d", &x, &l, &r);
      if(x & 1) update(ns, st, 1, 0, N-1, l-1, r);
      else{
				Node ans = query(ns, st, 1, 0, N-1, l-1, r-1);
				printf("%d\n", ans.dif(ns));
      }
			//for(int j = 0; j < 4*N; j++) printf("%d min: %d max %d\n", j, st[j].min, st[j].max);
    }
  }
  return 0;
}

