// https://codeforces.com/contest/1996/problem/E
#pragma GCC optimize("Ofast")
#pragma GCC optimization("unroll-loops")

#include <bits/stdc++.h>
using namespace std;

#define int long long
typedef pair<int, int> pi;
#define f first
#define s second
#define mp make_pair
#define MULTI_TEST (1)
const int maxn = 2e5 + 5, inf = 1e18, mod = 1e9 + 7;
string s;

// (pr[i] - pr[j]) * 2 = i - j
// 2 * pr[i] - 2 * pr[j] = i - j
// 2 * pr[i] - i = 2 * pr[j] - j


void solve() {
    cin >> s;
    int n = s.size();
    vector<int> pr(n);
    for (int i = 0; i < n; ++i)
        pr[i] = (i ? pr[i - 1] : 0) + (s[i] == '1');
    map<int, int> cnt;
    cnt[1] = 1;
    int ans = 0;
    for (int i = 0; i < n; ++i) {
        int val = 2 * pr[i] - i;
        int right = n - i;
        int left = cnt[val];
        ans = (ans + (left * right) % mod) % mod;
        cnt[val] += i + 2;
    }
    cout << ans << '\n';
}

signed main() {
    ios_base::sync_with_stdio(0); 
    cin.tie(0); cout.tie(0);

    int t = 1;
    if (MULTI_TEST) cin >> t;
    while (t--) solve();

    return 0;
}
