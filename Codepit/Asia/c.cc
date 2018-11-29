#include<bits/stdc++.h>
using namespace std;

typedef uint64_t ull;

int main(void) {
    ull A, B;
    ios_base::sync_with_stdio(false);
    while(cin >> A >> B) {
        ull tta = 0, ttb = 0;
        A -= 1;
        for(int i = 1; i < 63; ++i) {
            ull x = 1L << i;
            tta = tta + (x >> 1) * (A / x) + (A % x > (x / 2 - 1) ? (A % x) - (x / 2 - 1) : 0);
            ttb = ttb + (x >> 1) * (B / x) + (B % x > (x / 2 - 1) ? (B % x) - (x / 2 - 1) : 0);
        }
        cout << ttb - tta << "\n";
    }

    return 0;
}
