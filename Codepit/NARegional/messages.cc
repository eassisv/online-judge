#include<bits/stdc++.h>
using namespace std;

const uint32_t MAX = 2e4 + 7;

int main(void) {
    char s[MAX];
    while(scanf("%s", s) != EOF) {
        int rot1 = 0, rot2 = 0, *r;
        for(int c = 0; c < 2; c++) {
            r = &rot1;
            for(int i = 0, l = strlen(s); i < l; ++i, r = i < l/2 ? &rot1 : &rot2) {
                if(!c) *r += (s[i] - 'A');        
                else s[i] = 'A' + ((s[i] - 'A' + *r) % 26);
            }
        }
        for(int i = 0, j = strlen(s)/ 2; i < j; i++) s[i] = 'A' + ((s[i] - 'A' + (s[i + j] - 'A')) % 26);
        s[strlen(s)/2] = '\0';
        printf("%s\n", s);
    }
    return 0;
};

