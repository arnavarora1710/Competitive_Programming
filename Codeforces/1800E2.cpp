// https://codeforces.com/contest/1800/problem/E2
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
int n, k; string s, t;

void submit(bool yes) {
    cout << (yes ? "YES\n" : "NO\n");
}

void solve() {
    cin >> n >> k >> s >> t;
    map<char, int> cnt, cnt1;
    for (int i = 0; i < n; ++i)
        cnt[s[i]]++, cnt1[t[i]]++;
    if (cnt != cnt1) submit(0);
    else {
        int lo = n - k, hi = k - 1;
        if (lo < 0 || hi >= n) submit(s == t);
        else {
            for (int i = lo; i <= hi; ++i) {
                if (s[i] != t[i]) {
                    submit(0);
                    return;
                }
            }
            submit(1);
        }
    }
}

signed main() {
    ios_base::sync_with_stdio(0); 
    cin.tie(0); cout.tie(0);

    int tc = 1;
    if (MULTI_TEST) cin >> tc;
    while (tc--) solve();
    return 0;
}