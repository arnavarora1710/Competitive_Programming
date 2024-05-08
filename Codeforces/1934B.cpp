// https://codeforces.com/contest/1934/problem/B
#pragma GCC optimize("Ofast")
#pragma GCC optimization("unroll-loops")

#include <bits/stdc++.h>
using namespace std;

#define int long long
#define MULTI_TEST (1)

void solve() {
    int n; cin >> n;
    int cur = n, ans = cur/15;
    int rem = (cur/15) * 15;
    int remm = cur - rem;
    if (cur < 15) {
        if (cur == 1 || cur == 3 || cur == 6 || cur == 10)
            ans = 1;
        else if (cur == 2 || cur == 4 || cur == 7 || cur == 9 || cur == 11 || cur == 12 || cur == 13) ans = 2;
        else if (cur == 5 || cur == 8 || cur == 14) ans = 3;
    }
    else if (remm == 1 || remm == 3 || remm == 6
        || remm == 10 || remm == 5) ans++;
    else if (remm == 2 || remm == 4 || remm == 7 || remm == 11
            || remm == 8 || remm == 9 || remm == 12 || remm == 13)
            ans += 2;
    else if (remm == 14) ans += 3;
    cout << ans << endl;
}

signed main() {
    ios_base::sync_with_stdio(0); 
    cin.tie(0); cout.tie(0);

    int t = 1;
    if (MULTI_TEST) cin >> t;
    while (t--) solve();

    return 0;
}