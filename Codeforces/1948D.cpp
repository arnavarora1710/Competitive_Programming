// https://codeforces.com/contest/1948/problem/D
#pragma GCC optimize("Ofast")
#pragma GCC optimization("unroll-loops")

#include <bits/stdc++.h>
using namespace std;

#define int long long
typedef pair<int, int> pi;
#define f first
#define s second
#define MULTI_TEST (1)
string a;

void solve() {
    cin >> a;
    int n = a.size(), ans = 0;
    for (int dis = 1; dis <= (n + 1) / 2; ++dis) {
        vector<int> cnts(n);
        for (int i = 0; i + dis < n; ++i) {
            if (a[i] == '?' || a[i + dis] == '?' ||
                a[i] == a[i + dis])
                cnts[i] = 1;
        }
        int cnt = 0;
        for (int i = 0; i < n; ++i) {
            if (!cnts[i]) {
                if (cnt >= dis) {
                    ans = max(ans, dis << 1);
                }
                cnt = 0;
            } else cnt++;
        }
    }
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