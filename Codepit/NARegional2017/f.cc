#include<bits/stdc++.h>
using namespace std;

#define pb push_back
#define mp make_pair
#define f first
#define s second

const int NIL = -1;
const int MAX = 1e5+7;
vector< vector<int> > g(MAX);
vector< bool > seen(MAX, false), art(MAX, false);
vector< int > p(MAX), childs(MAX);

void dfs(int u) {
    seen[u] = true;
    art[u] = false;
    int lchilds = 0, tchilds = 0;
    for(int i = 0; i < (int)g[u].size(); i++) {
        int v = g[u][i];
        if(!seen[v]) {
            p[v] = u;
            lchilds++;
            dfs(v);
            tchilds += childs[v];
            if(p[u] == u)  {
                art[u] = lchilds >= 2;
            }
            else if(lchilds) art[u] = true;
        }
    }
    childs[u] = lchilds + tchilds;
}

int main(void) {
    int n, x, y, m;
    while(cin >> n) {
        m = 0;
        for(int i = 0; i < n; i++) {
            scanf("%d %d", &x, &y);
            g[x].pb(y);
            g[y].pb(x);
            m = max(m, max(x, y));
        }
        n = m;
        p[0] = 0;
        dfs(0);
        int V = 0, ans = 0;
        for(int i = 0; i <= n; i++) {
            if(art[i]) {
                int temp = 0;
                int rchilds = childs[0] - childs[i];
                for(int j = 0; j < (int)g[i].size(); j++) {
                    if(p[i] == g[i][j]) continue;
                    temp = temp + rchilds * (childs[g[i][j]] + 1);
                    for(int k = j + 1; k < (int)g[i].size(); k++) {
                        if(p[i] == g[i][k]) continue;
                        temp = temp + (childs[g[i][j]] + 1) * (childs[g[i][k]] + 1);
                    }
                }
                if(temp > ans) {
                    V = i;
                    ans = temp;
                }
            }
        }
        int m1 = 0, m2  = childs[0] - childs[V];
        for(int i = 0; i < (int)g[V].size(); i++) {
            if(m1 > m2) swap(m1, m2);
            if(p[V] == g[V][i]) continue;
            if(childs[g[V][i]] + 1 > m1) m1 = 1 + childs[g[V][i]];
        }
        cout << ans << ' ' << ans - m1 * m2 << '\n';
        for(int i = 0; i <= n; i++) {
            g[i].clear();
        }
        seen.assign(MAX, false);
        art.assign(MAX, false);
        
    }
    return 0;
}
