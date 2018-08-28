#include<bits/stdc++.h>
using namespace std;

#define pb push_back
#define mp make_pair
#define f first
#define s second

const int MAX = 1e5+1;
const char *cs = "aeiou";

char m[31][31];

int main(void) {
    int n;
    char key[51];
    scanf("%s", key);
    scanf("%d", &n);
    getchar();
    int k = 0, lk = strlen(key);
    for(int i = 0; i < n; ++i) {
        bool s = true, p;
        char c;
        k = 0;
        while(scanf("%c", &c) && c != '\n') {
            if(c == ' ') { printf(" "); s = true; continue; }
            if(s) { p = false; for(int j = 0; !p && j < 5; ++j) p = (c == cs[j]); s = !s; }
            if(p) printf("%c", c);
            else {
                printf("%c", ((key[k % lk] - 'a' + (c - 'a')) % 26) + 'a');
                k++;
            }
        }
        printf("\n");
    }
    return 0;
}

