#include<bits/stdc++.h>
using namespace std;

int main(void) {
    int N, t, ans;
    vector<int> vs(1e4 + 1);
    while(cin >> N) {
        t = 0;
        for(int i = 0; i < N; ++i) {
            int x;
            scanf("%d", &x);
            t += vs[i] = x;
        }
        if(t % N) ans = -1;
        else{
            t /= N;
            ans = 0;
            for(int i = 0; i < N; i++)
                ans += abs(vs[i] - t);
            ans = ans / 2 + 1;
        }
        printf("%d\n", ans);
    }
    return 0;
}
