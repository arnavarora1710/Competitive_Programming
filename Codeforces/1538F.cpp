// https://codeforces.com/problemset/problem/1538/F
#pragma GCC optimize("Ofast")
#pragma GCC optimization("unroll-loops")

#include <bits/stdc++.h>
using namespace std;

#define int long long
#define MULTI_TEST (1)
int l, r;

void solve() {
    cin >> l >> r;
    auto f = [&] (int n) {
        int ans = 0, cnt = 1;
        for (int i = 0; i <= 9; ++i) {
            ans += n / cnt;
            cnt *= 10;
        }
        return ans;
    };
    cout << f(r) - f(l) << endl;
}

signed main() {
    ios_base::sync_with_stdio(0); 
    cin.tie(0); cout.tie(0);

    int t = 1;
    if (MULTI_TEST) cin >> t;
    while (t--) solve();

    return 0;
}