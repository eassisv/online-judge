#include<bits/stdc++.h>
using namespace std;

const int MAXN = 1e2+7, MAXM = 2e4+7;

vector<int> vs(MAXN);

int mm[MAXN][MAXM][3];

int n, m;

int pd(int i, int j, int r) {
    if(i >= n) return 0;
    if(mm[i][j][r] != -1) { return mm[i][j][r]; }
    int a = 0, b, x;
    a = m;
    for(int k = 0; k < j; k++) a = a * 2 / 3;
    x = min(vs[i], a);
    a = x + pd(i + 1, j + 1, 0);
    int nj;
    if(!r) {
        nj = max(j - 1, 0);
    }else{
        nj = 0;
    }
    b = pd(i + 1, nj, 1);
    return mm[i][j][r] = max(a, b);
}

int main(void) {
    while(cin >> n >> m) {
        memset(mm, -1, sizeof(mm));
        for(int i = 0; i < n; i++) {
            int x;
            scanf("%d", &x);
            vs[i] = x;
        }
        printf("%d\n", pd(0, 0, 0));
    }
    return 0;
}

