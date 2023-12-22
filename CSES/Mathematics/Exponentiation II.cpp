#include <bits/stdc++.h>
using namespace std;
#define int long long
const int mod = 1e9 + 7;
int t, x, y, z;

int pw(int a, int b, int m) {
    int res = 1;
    while (b) {
        if (b&1) res = (res * a) % m;
        a = (a * a) % m;
        b >>= 1;
    }
    return res;
}

signed main() {
    cin >> t;
    while (t--) {
        cin >> x >> y >> z;
        cout << pw(x, pw(y, z, mod - 1), mod) << endl;
    }
    return 0;
}