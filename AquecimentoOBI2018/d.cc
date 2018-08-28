#include<bits/stdc++.h>
using namespace std;

#define pb push_back
#define mp make_pair
#define f first
#define s second
typedef pair<int, int> ii;

const int MAX = 1e3 + 7;

int vs[MAX][MAX];
vector< vector<int> > ns(MAX), ms(MAX);
int m, n;

int main(void) {
    char c;
    cin >> n >> m;
    cin.ignore();
    for(int i = 0; i < n; ++i) {
        for(int j = 0; j < m; ++j) {
            scanf("%c", &c);
            if(c == '@') {
                ns[i].pb(j);
                ms[j].pb(i);
            }
            vs[i][j] = MAX;
        }
        getchar();
    }
    for(int i = 0; i < n; ++i) {
        for(int j = 0; j < (int)ns[i].size(); ++j){
            int l = j ? (ns[i][j - 1] + ns[i][j]) / 2 : -1;
            int r = j + 1 != ns[i].size() ? (ns[i][j] + ns[i][j + 1]) / 2 + 1 : m;
            int jj = ns[i][j] - 1;
            vs[i][ns[i][j]] = 0;
            while(jj > l) { vs[i][jj] = vs[i][jj + 1] + 1; --jj; }
            jj = ns[i][j] + 1;
            while(jj < r) { vs[i][jj] = vs[i][jj - 1] + 1; ++jj; }
        }
    }
    for(int i = 0; i < m; ++i) {
        for(int j = 0; j < (int)ms[i].size(); ++j){
            int l = j ? (ms[i][j - 1] + ms[i][j]) / 2 : -1;
            int r = j + 1 != ms[i].size() ? (ms[i][j] + ms[i][j + 1]) / 2 + 1 : n;
            int jj = ms[i][j] - 1;
            int v = 1;
            vs[ms[i][j]][i] = 0;
            while(jj > l) { 
                vs[jj][i] = min(v, vs[jj][i]);
                --jj;
                ++v;
            }
            jj = ms[i][j] + 1;
            v = 1;
            while(jj < r) {
                vs[jj][i] = min(v, vs[jj][i]); 
                ++jj;
                ++v;
            }
        }
    }
    int ans = 0;
    for(int i = 0; ans != -1 && i < n; ++i){
        for(int j = 0; j < m; ++j){
            if(vs[i][j] == MAX) { ans = -1; break; }
            else ans = max(ans, vs[i][j]);
        }
    }       
    cout << ans << "\n";
    return 0;
}

