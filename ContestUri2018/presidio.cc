#include<bits/stdc++.h>
using namespace std;

#define pb push_back
#define f first
#define s second
#define mp make_pair
#define LEFT(x) x << 1
#define RIGHT(x) (x << 1) + 1
typedef pair<int, int> ii;

const int MAX = 2e5+1;
const int INF = 1 << 30;
vector<ii> ns;
vector<ii> tree(4 * MAX, mp(-INF, INF));

void build(int i, int l, int r) {
    if(l == r) { tree[i] = ns[l]; return; }
    int m = (l + r) >> 1;
    build(LEFT(i), l, m);
    build(RIGHT(i), m + 1, r);
    ii a = tree[LEFT(i)], b = tree[RIGHT(i)];
    tree[i] = mp(max(a.f, b.f), min(a.s, b.s));
}

void update(int i, int l, int r, int idx, ii p) {
    if(l == r) { 
        ns[idx] = p;
        tree[i] = p;
        return;
    }
    int m = (l + r) >> 1;
    if(l <= idx && m >= idx) update(LEFT(i), l, m, idx, p);
    else update(RIGHT(i), m + 1, r, idx, p);
    ii a = tree[LEFT(i)], b = tree[RIGHT(i)];
    tree[i] = mp(max(a.f, b.f), min(a.s, b.s));
}

ii query(int idx, int l, int r, int i, int j) {
    if(l > j || r < i) return mp(-INF, INF);
    if(l >= i && r <= j) return tree[idx];
    int m = (l + r) >> 1;
    ii a = query(LEFT(idx), l, m, i, j);
    ii b = query(RIGHT(idx), m + 1, r, i, j);
    return mp(max(a.f, b.f), min(a.s, b.s));
}

int main(void) {
    int N, Q;
    cin >> N >> Q;
    for(int i = 0; i < N; i++) {
        int l, r;
        scanf("%d %d ", &l, &r);
        ns.pb(mp(l, r));
    }
    build(1, 0, N - 1);
    char c;
    int l, r, rr;
    for(int i = 0; i < Q; i++) {
        scanf("%c %d %d ", &c, &l, &r);
        if(c == 'C') {
            scanf("%d ", &rr);
            update(1, 0, N - 1, l - 1, mp(r, rr));
        }else {
            ii ans = query(1, 0, N - 1, l - 1, r - 1);
            printf("%d\n", ans.s >= ans.f ? (ans.s - ans.f) + 1: 0);
        }
    }
}
