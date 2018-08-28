#include<bits/stdc++.h>
using namespace std;

int main(void) {
    int N;
    cin >> N;
    vector<int> vs(1e5 + 1), ans(1e5 + 1);
    for(int i = 0; i < N; ++i) {
        int x;
        scanf("%d", &x);
        vs[i] = x;
    }
    for(int i = N - 1; i >= 0; --i) {
        if(i == N - 1) ans[i] = -1;
        else {
            if(vs[i + 1] > vs[i]) {
                ans[i] = (vs[i + 1]);
                continue;
            }
            ans[i] = -1;
            for(int j = i + 1; j < N; ++j) {
                if(ans[j] > vs[i]) {
                    ans[i] = ans[j];
                    break;
                }
            }
        }
    }
    for(int i = 0; i < N; ++i) {
        if(ans[i] == -1) printf("*");
        else printf("%d", ans[i]);
        if(i < N - 1) printf(" ");
    }
    printf("\n");
    return 0;
}
