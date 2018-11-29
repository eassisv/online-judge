#include<bits/stdc++.h>
using namespace std;

int main(void) {
    int N, G;
    vector<int> vs(1e5);
    while(scanf("%d %d", &N, &G) != EOF) {
        int ind = 0, ans = 0;
        for(int i = 0; i < N; ++i) {
            int s, r;
            scanf("%d %d", &s, &r);
            if(s > r) {
                ans += 3;
                continue;
            }
            vs[ind++] = r - s;
        }
        sort(&vs[0], &vs[ind]); 
        for(int i = 0; i < ind; ++i) {
            if(G > vs[i]) {
                ans += 3;
                G -= (vs[i] + 1);
            }else if(G == vs[i]) {
                ans += 1;
                G -= vs[i];
            }else{
                if(!vs[i]) ans += 1;
                else break;
            }
        }
        cout << ans << "\n";
    }
    return 0;
}
