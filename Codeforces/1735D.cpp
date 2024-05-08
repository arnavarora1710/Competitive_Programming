// https://codeforces.com/contest/1735/problem/D
#pragma GCC optimize("Ofast")
#pragma GCC optimization("unroll-loops")

#include <bits/stdc++.h>
using namespace std;

#define int long long
typedef pair<int, int> pi;
#define f first
#define s second
#define MULTI_TEST (0)
const int maxn = 2e5 + 5, inf = 1e18;
int n, k; string a[maxn];
unordered_map<string, int> mp;

void solve() {
    cin >> n >> k;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < k; ++j) {
            char ch; cin >> ch;
            a[i] += ch;
        }
    }
    map<string, int> cnt;
    for (int i = 0; i + 2 < n; ++i) {
        mp.clear();
        for (int j = i + 1; j < n; ++j) mp[a[j]]++;
        for (int j = i + 1; j + 1 < n; ++j) {
            string s(k, ' ');
            mp[a[j]]--;
            for (int kk = 0; kk < k; ++kk) {
                if (a[i][kk] == a[j][kk]) s[kk] = a[i][kk];
                else s[kk] = '0' + '1' + '2' - a[i][kk] - a[j][kk];
            }
            if (mp[s]) {
                cnt[a[i]]++;
                cnt[a[j]]++;
                cnt[s]++;
            }
        }
    }
    int ans = 0;
    for (auto& i : cnt) ans += (i.s * (i.s - 1)) / 2;
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
