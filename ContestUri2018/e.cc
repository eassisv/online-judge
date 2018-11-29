#include<bits/stdc++.h>
using namespace std;

#define pb push_back

map<string, bool> vis;
map<string, vector<string> > g;

void dfs(string s) {
    vis[s] = true;
    for(int i = 0; i < (int)g[s].size(); ++i) {
        string a = g[s][i];
        if(!vis[a]) dfs(a);
    }
}

int main(void) {
    int M, N;
    string a, b, c;
    ios_base::sync_with_stdio(false);
    cin >> M >> N;
    for(int i = 0; i < N; ++i) {
        cin >> a >> b >> c;
        g[a].pb(c);
        g[c].pb(a);
        if(vis.find(a) == vis.end()) vis[a] = false;
        if(vis.find(c) == vis.end()) vis[c] = false;
    }
    int ans = 0;
    for(auto i : vis) {
        if(vis[i.first]) continue;
        ans++;
        dfs(i.first);
    }
    cout << ans << "\n";
    return 0;
}

