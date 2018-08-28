#include<bits/stdc++.h>
using namespace std;

#define pb push_back
#define mp make_pair
#define f first
#define s second
typedef vector<int64_t> vi;
typedef int64_t ll;

const int MAX = 1e6 + 7;

vi ds(MAX), es(MAX);

int main(void) {
    ll D, E, ans;
    cin >> D >> E;
    ans = (D + 1L) * (E + 1L);
    ds[0] = es[0] = 0L;
    for(ll i = 1; i <= E; ++i) ds[i] = D * i;
    for(ll i = 1; i <= D; ++i) es[i] = E * i;
    for(ll i = 0, j = 0, *ind; i <= D; ++(*ind)) {
        if(llabs(ds[i] - es[j]) == 1) { ans = i + j; break; }
        if(ds[i] > es[j]) ind = &j;
        else ind = &i;
    }
    for(ll i = 0, j = 0, *ind; i <= E; ++(*ind)) {
        if(llabs(es[i] - ds[j]) == 1) { ans = min(ans, i + j); break; }
        if(es[i] > ds[j]) ind = &j;
        else ind = &i;
    }
    if(ans == (D + 1L) * (E + 1L)) cout << "IMPOSSIVEL\n";
    else cout << ans << "\n";
    return 0;
}

