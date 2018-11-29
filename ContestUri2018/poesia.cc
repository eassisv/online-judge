#include<bits/stdc++.h>
using namespace std;

#define pb push_back
const int MAX = 2e3+1;

vector<int> divs, ns, rs(MAX);

int main(void) {
    int N, ans;
    cin >> N;
    for(int i = 2, j = N, d = 0; j > 1;){
        if(j % i) { d = 0; ++i; continue; }
        if(!d) { d = 1; divs.pb(i); }
        else { int x = i * divs.back(); divs.pb(x); }
        j /= i;
    }
    sort(divs.begin(), divs.end());
    for(int i = 0; i < N; i++) {
        int x;
        scanf("%d", &x);
        ns.pb(x);
    }
    ans = -1;
    for(auto i : divs) {
        int x = N / i;
        for(auto j : ns){
            rs[j % i] += 1;
        }
        ans = i;
        for(int j = 0; j < i; j++) {
            if(rs[j] != x) ans = -1;
            rs[j] = 0;
        }
        if(ans != -1) break;
    }
    cout << ans << '\n';
}
