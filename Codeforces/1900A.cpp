#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
#pragma GCC optimization("unroll-loops")

#include <bits/stdc++.h>
using namespace std;

#define int long long
#define MULTI_TEST (1)
int n; string a;

void solve() {
    cin >> n >> a;
    bool ok = false; int cnt = 0, ans = 0;
    for (int i = 0; i < n; ++i) {
        if (a[i] == '.') cnt++;
        else {
            if (cnt >= 3) ok = true;
            ans += cnt, cnt = 0;
        }
    }
    ans += cnt;
    cout << (ok || cnt >= 3 ? 2 : ans) << endl;
}

signed main() {
    ios_base::sync_with_stdio(0); 
    cin.tie(0); cout.tie(0);

    int t = 1;
    if (MULTI_TEST) cin >> t;
    while (t--) solve();

    return 0;
}