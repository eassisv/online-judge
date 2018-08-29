#include<bits/stdc++.h>
using namespace std;

const int MAX = 1e3+7;
vector< vector<int> > mm(MAX, vector<int> (MAX, -1));
string s;
int n;
list< int > D;

int pd(int idx, int m) {
    if(idx == (int)s.size()) return !m;
    if(mm[idx][m] != -1) return mm[idx][m];
    int ans, x;
    if(s[idx] != '?') {
        x = s[idx] - '0';
        ans = pd(idx + 1, (m * 10 + x) % n);
    }else {
        x = !idx ? 1 : 0;
        for(ans = 0; !ans && x < 10; x++) {
            ans = pd(idx + 1, (m * 10 + x) % n);
        }
        x--;
    }
    if(ans) D.push_front(x);
    return mm[idx][m] = ans;

}

int main(void) {
    cin >> s >> n;
    int ans = pd(0, 0);
    if(ans) for(auto i : D) cout << i;
    else cout << '*';
    cout << '\n';
    return 0;
}
