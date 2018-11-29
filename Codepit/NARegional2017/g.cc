#include<bits/stdc++.h>
using namespace std;

#define pb push_back
#define mp make_pair
#define f first
#define s second
typedef vector<int> vi;

const int MAX = 1e3+7;

vi w(MAX), v(MAX);
vector< vi > mm(MAX, vi(MAX));
vector<char> s(MAX);
const char *ss = "CBG";
int n, r;

int pd() {
    int ans = 0;
    for(int k = 0; k < 3; ++k) {
        for(int i = 0; i <= n; ++i) mm[i][0] = 0;
        for(int i = 0; i <= r; ++i) mm[0][i] = 0;
        for(int i = 1; i <= n; ++i) {
            for(int j = 1; j <= r; ++j) {
                if(w[i] > j || s[i] == ss[k]) mm[i][j] = mm[i - 1][j];
                else {
                    mm[i][j] = max(v[i] + mm[i - 1][j - w[i]], mm[i - 1][j]);
                }
            }
        }
        ans = max(ans, mm[n][r]);
    }
    return ans;
}

int main(void) {
    cin >> n >> r;
    for(int i = 1; i <= n; ++i) {
        int a, b;
        char c;
        scanf("%d %c %d", &a, &c, &b);
        v[i] = a; s[i] = c; w[i] = b;
    }
    cout << pd() << '\n';
    return 0;
}
