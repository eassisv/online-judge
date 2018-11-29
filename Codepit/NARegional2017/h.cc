#include<bits/stdc++.h>
using namespace std;

#define mp make_pair
const int MAX = 1e2+7;
typedef pair<int, int> ii;


const int my[] = {0, 0, 1, -1, 1, -1, 1, -1};
const int mx[] = {1, -1, 0, 0, 1, 1, -1, -1};
vector< vector<char> > gr(MAX, vector<char> (MAX));
vector< vector<ii> > p(MAX, vector<ii> (MAX, mp(-1, -1)));
int m, n;

int dfs(int i, int j) {
    gr[i][j] = '@';
    int cycles = 0;
    for(int k = 0; k < 8; k++) {
        int ii = i + my[k];
        int jj = j + mx[k];
        if(ii < 0 || ii >= m || jj < 0 || jj >= n) continue;
        if(gr[ii][jj] == '#') {
            p[ii][jj] = mp(i, j);
            cycles += dfs(ii, jj);
        }else if(gr[ii][jj] == '@'){
            if(p[i][j] == mp(-1, -1)) continue;
            cycles += p[i][j] != mp(ii, jj);
        }
    }
    return cycles;
}

int main(void) {
    while(cin >> m >> n) {
        cin.ignore();
        for(int i = 0; i < m; i++, cin.ignore())
            for(int j = 0; j < n; j++) {
                char x;
                scanf("%c", &x);
                gr[i][j] = x;
            }
        int ans = 0;
        for(int i = 0; i < m; i++)
            for(int j = 0; j < n; j++) {
                if(gr[i][j] == '#') ans += dfs(i, j);
            }
        cout << ans << '\n';
        p.assign(MAX, vector<ii> (MAX, mp(-1, -1)));
    }
}
