#include<bits/stdc++.h>
using namespace std;

const int MAX = 1e3+7;
vector< vector<int> > mm(MAX, vector<int> (MAX, -1));

int mod(string s, int n) {
    int r = 0;
    cout << s.size() << endl;
    for(int i = 0; i < s.size(); i++) {
        int x = s[i] - '0';
        r = r * 10 + x; 
        r = x % n;
    }
    return r;
}

int pd(int idx, int m, string &s) {
    if(idx == -1) return m;
    
    

}

int main(void) {
    string s;
    int n;
    cin >> s >> n;
    cout << s << ' ' << n << endl;
    for(int i = 0; i < (int)s.size(); i++) {
        if(!i && s[i] == '?') s[i] = '1';
        else if(s[i] == '?') s[i] = '0';
    }
    cout << pd((int)s.size() - 1, mod(s, n), s) << '\n'; 

    return 0;
}
