#include<bits/stdc++.h>
using namespace std;

#define pb push_back
#define mp make_pair
#define f first
#define s second

const int MAX = 3e5+1;
vector<int> graph(MAX, 0);

int main(void) {
    int N, M, K;
    cin >> N >> M >> K;
    for(int i = 0; i < M; i++) {
        int a, b;
        scanf("%d %d", &a, &b);
        graph[a] = (graph[a] + 1) % 2;
        graph[b] = (graph[b] + 1) % 2;
    }
    vector< pair<int, int> > ans;
    for(int i = 0; i < K; i++) {
        int a, b;
        scanf("%d %d", &a, &b);
        if(graph[a] & 1 && graph[b] & 1) {
            ;
        }
    }

    return 0;
}
