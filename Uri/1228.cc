#include<bits/stdc++.h>
using namespace std;

int main(void) {
    int N, ans;
    vector<int> vs;
    while(cin >> N) {
        for(int i = 0; i < N; ++i) {
            int x;
            scanf("%d", &x);
            vs.push_back(x);
        }
        ans = 0;
        for(int i = 0; i < N; ++i) {
            int x;
            scanf("%d", &x);
            for(int j = i; j < N; ++j) {
                if(x == vs[j]) {
                    int jj = j;
                    while(jj > i) {
                        swap(vs[jj - 1], vs[jj]);
                        ans++;
                        jj--;
                    }
                break;
                }
            }
        }
        printf("%d\n", ans);
        vs.clear();
    }
    return 0;
}
