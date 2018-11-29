#include<bits/stdc++.h>
using namespace std;

#define pb push_back
#define mp make_pair
#define f first
#define s second

const int MAX = 1e5+7;
const int MAXN = 1e4+7;
map <string, int> m;
vector< vector<int> > has(MAX, vector<int> (MAX, 0)), is(MAX, vector<int> (MAXN, 0));
vector< vector<bool> > bhas(MAX, vector<bool> (MAX, false)), bis(MAX, vector<bool> (MAX, false));

int main(void) {
    int n, mx;
    string a, b, x;
    ios_base::sync_with_stdio(false);
    while(cin >> n >> mx) {
        int mm = 0;
        cin.ignore();
        for(int i = 0; i < n; i++) {
            cin >> a >> x >> b;
            cin.ignore();
            cout << a << ' ' << x << ' ' << b << endl;
            int ia, ib;
            ia = (m.find(a) == m.end()) ? mm++ : m[a];
            cout << a << ' ' << ia << endl;
            ib = (m.find(b) == m.end()) ? mm++ : m[b];
            if(x[0] == 'i') {
                is[ia][ia / 32] |= (1 << (ia - 1));
                for(int j = 0; j <= (mm / 32); j++) {
                    is[ia][j] |= is[ib][j];
                }
            }else {
                has[ia][ia / 32] |= (1 << (ia - 1));
                for(int j = 0; j <= (mm / 32); j++) {
                    has[ia][j] |= has[ib][j];
                }
            } 
        }
        for(int i = 0; i < mm; i ++) {
            for(int j = 0; j <= mm / 32; j++) {
                cout << is[i][j] << ' ';
            }
            cout << '\n';
        }
    }

    return 0;
}

