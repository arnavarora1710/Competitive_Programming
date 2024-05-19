// https://codeforces.com/contest/1822/problem/E
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")

#include <bits/stdc++.h>
using namespace std;

#define int long long

typedef pair<int, int> pi;
typedef pair<int, char> pc;
#define f first
#define s second
#define MULTI_TEST (1)
const int maxn = 2e5 + 5, inf = 1e18;
int n; string s;

void solve() {
    cin >> n >> s;
    if (n&1) cout << -1 << '\n';
    else {
        int cnt[26] = {0};
        for (int i = 0; i < n; ++i) cnt[s[i] - 'a']++;
        for (int i = 0; i < 26; ++i) {
            if (cnt[i] > n / 2) {
                cout << -1 << '\n';
                return;
            }
            cnt[i] = 0;
        }
        int k = 0;
        for (int i = 0; i < n / 2; ++i) {
            if (s[i] == s[n - i - 1]) {
                k++; cnt[s[i] - 'a']++;
            }
        }
        for (int i = 0; i < 26; ++i) {
            if (cnt[i] * 2 > k) {
                cout << cnt[i] << '\n';
                return;
            }
        }
        cout << (k + 1) / 2 << '\n';
    }
}

signed main () {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t = 1;
    if (MULTI_TEST) cin >> t;
    while (t--) solve();

    return 0;
}
