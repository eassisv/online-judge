#include<bits/stdc++.h>
using namespace std;

#define pb push_back
#define mp make_pair
#define f first
#define s second
typedef vector<int> vi;

vi vs;

int main(void) {
    int n, m, pos, ff = 1;
    while(cin >> n) {
        for(int i = 0; i < n; ++i) {
            int x;
            scanf("%d", &x);
            vs.pb(x);
        }
        cin >> m;
        for(int i = 0; i < n; ++i) if(vs[i] == m) pos = i + 1;
        char ans = 'Y';
        for(int i = 2; i <= pos; ++i) {
            if(pos % i == 0) { ans = 'N'; break; }
            pos -= ((pos - 1) / i);
        }
        printf("%c\n", ans);
        vs.clear();
    }
    
    return 0;
}

