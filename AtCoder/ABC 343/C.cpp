#pragma GCC optimize("Ofast")
#pragma GCC optimization("unroll-loops")

#include <bits/stdc++.h>
using namespace std;

#define int long long
#define MULTI_TEST (0)

bool checkPal(int x) {
    vector<int> digs;
    while (x) {
        digs.push_back(x%10);
        x /= 10;
    }
    vector<int> rev = digs;
    reverse(digs.begin(), digs.end());
    return digs == rev;
}

int power(int x, int y) {
    int res = 1;
    while (y) {
        if (y&1) res *= x;
        x *= x;
        y >>= 1;
    }
    return res;
}

void solve() {
    int n; cin >> n;
    for (int i = min((int) 1e6, n); i >= 0; --i) {
        int num = power(i, 3);
        if (num > n) continue;
        if (checkPal(num)) {
            cout << num;
            break;
        }
    }
}

signed main() {
    ios_base::sync_with_stdio(0); 
    cin.tie(0); cout.tie(0);

    int t = 1;
    if (MULTI_TEST) cin >> t;
    while (t--) solve();

    return 0;
}