#include<bits/stdc++.h>
using namespace std;

#define pb push_back
#define mp make_pair
#define f first
#define s second

const int MAX = 1e5+7;
vector<int> ft(MAX, 0);

void update(int i, int v, int N) {
    for(; i <= N; i += i & (-i)) ft[i] += v;
}

int rsq(int i) { 
    int t = 0;
    for(; i; i -= i & (-i)) t += ft[i];
    return t;
}

int rsq(int a, int b, int c, int d) {
    if(b < c || d < a) { 
        return rsq(b) - rsq(a - 1) + rsq(d) - rsq(c - 1);
    }
    return rsq(max(b, d)) - rsq(min(a, c) - 1);
}

int main(void) {
    int N, M, x, a, b, c, d;
    cin >> N >> M;
    for(int i = 0; i < M; i++) {
        scanf("%d", &x);
        if(x == 1) {
            scanf("%d %d", &a, &b);
            update(a, b, N);
        }else {
            scanf("%d %d %d %d", &a, &b, &c, &d);
            cout << rsq(a, b, c, d) << '\n';
        }
    }
    return 0;
}

