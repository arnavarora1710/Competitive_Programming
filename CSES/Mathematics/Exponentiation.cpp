#include <bits/stdc++.h>
using namespace std;
#define int long long
const int mod = 1e9 + 7;
int t, a, b;

signed main() {
    cin >> t;
    while (t--) {
        cin >> a >> b;
        int res = 1;
        while (b) {
            if (b&1) res = (res * a) % mod;
            a = (a * a) % mod;
            b >>= 1;
        }
        cout << res << endl;
    }
    return 0;
}