// https://codeforces.com/contest/1332/problem/C
#pragma GCC optimize("Ofast")
#pragma GCC optimization("unroll-loops")

#include <bits/stdc++.h>
using namespace std;

#define int long long
typedef pair<int, int> pi;
#define f first
#define s second
#define MULTI_TEST (1)
const int maxn = 2e5 + 5, inf = 1e18;
int n, k; string s;

void solve() {
    cin >> n >> k >> s;
    int ans = 0;
    vector<bool> vis(n);
    for (int i = 0; i < n; ++i) {
        if (!vis[i]) {
            int j = i, ct = 0;
            vector<int> cnt(26);
            while (j < n) {
                vis[j] = true;
                cnt[s[j] - 'a']++;
                j += k;
                ct++;
            }
            j = k - i - 1;
            while (j < n) {
                if (vis[j]) break;
                vis[j] = true;
                cnt[s[j] - 'a']++;
                j += k;
                ct++;
            }
            int mx = *max_element(cnt.begin(), cnt.end());
            ans += ct - mx;
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
