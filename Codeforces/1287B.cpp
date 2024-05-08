// https://codeforces.com/contest/1287/problem/B
#pragma GCC optimize("Ofast")
#pragma GCC optimization("unroll-loops")

#include <bits/stdc++.h>
using namespace std;

#define int long long
typedef pair<int, int> pi;
#define f first
#define s second
#define MULTI_TEST (0)
const int maxn = 1505, inf = 1e18;
int n, k; string a[maxn];
unordered_map<string, int> mp;

void solve() {
    cin >> n >> k; for (int i = 0; i < n; ++i) cin >> a[i];
    int ans = 0;
    for (int i = 0; i + 2 < n; ++i) {
        mp.clear();
        for (int j = i + 1; j < n; ++j) mp[a[j]]++;
        for (int j = i + 1; j + 1 < n; ++j) {
            string s(k, ' ');
            mp[a[j]]--;
            for (int kk = 0; kk < k; ++kk) {
                if (a[i][kk] == a[j][kk]) s[kk] = a[i][kk];
                else s[kk] = 'S' + 'E' + 'T' - a[i][kk] - a[j][kk];
            }
            ans += mp[s];
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
