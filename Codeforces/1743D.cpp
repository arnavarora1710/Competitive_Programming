// https://codeforces.com/problemset/problem/1743/D
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")

#include <bits/stdc++.h>
using namespace std;

#define int long long

typedef pair<int, int> pi;
#define f first
#define s second
#define MULTI_TEST (0)
const int inf = 1e18;
int n;
string s;

void solve() {
    cin >> n >> s;
    string ans = s;
    vector<int> best(n);
    for (int i = n - 2; i >= 0; --i) {
        bool ok = 1;
        for (int j = 0; j < n - i - 1; ++j) {
            if (best[j] == 1) {
                ok = 0;
                break;
            }
        }
        if (!ok) continue;
        bool okk = 0;
        for (int l = 0, j = n - i - 1; j < n; ++l, ++j) {
            int val1 = s[j] - '0', val2 = s[l] - '0';
            if (!val1 && val2) { 
                if (!best[j]) okk = 1; 
                best[j] = 1;
            }
            else if (!okk && best[j] == 1) {
                ok = 0;
                break;
            }
            val1 = val1 | val2;
            if (okk) ans[j] = val1 + '0';
        }
        if (!ok) continue;
    }
    reverse(ans.begin(), ans.end());
    while (ans.size() > 1 && ans.back() == '0') ans.pop_back();
    reverse(ans.begin(), ans.end());
    cout << ans;
}

signed main () {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t = 1;
    if (MULTI_TEST) cin >> t;
    while (t--) solve();

    return 0;
}
