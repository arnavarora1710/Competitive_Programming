// https://codeforces.com/contest/1862/problem/F
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
const int maxn = 2e6 + 5, inf = 1e18;
int n, w, f, sum, a[maxn], dp[maxn];

bool check(int m) {
    int s1 = w * m, s2 = f * m;
    if (max(s1, s2) >= sum) return 1;
    for (int& x : dp) x = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = s1; j >= a[i]; --j) {
            dp[j] = max(dp[j], a[i] + dp[j - a[i]]);
        }
    }
    return sum - dp[s1] <= s2;
}

void solve() {
    cin >> w >> f >> n;
    if (w > f) swap(w, f);
    for (int i = 0; i < n; ++i) cin >> a[i];
    sum = 0; for (int i = 0; i < n; ++i) sum += a[i];
    int l = 0, r = 1e6 + 5;
    while (r - l > 1) {
        int m = l + (r - l) / 2;
        if (!check(m)) l = m;
        else r = m;
    }
    cout << r << '\n';
}

signed main() {
    ios_base::sync_with_stdio(0); 
    cin.tie(0); cout.tie(0);

    int t = 1;
    if (MULTI_TEST) cin >> t;
    while (t--) solve();

    return 0;
}