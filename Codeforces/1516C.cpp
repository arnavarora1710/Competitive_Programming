// https://codeforces.com/contest/1516/problem/C
#pragma GCC optimize("Ofast")
#pragma GCC optimization("unroll-loops")

#include <bits/stdc++.h>
using namespace std;

#define int long long
typedef pair<int, int> pi;
#define f first
#define s second
#define mp make_pair
#define MULTI_TEST (0)
const int maxn = 1e2 + 5, inf = 1e18;
int n, a[maxn];

void solve() {
    cin >> n;
    for (int i = 0; i < n; ++i) cin >> a[i];
    int sum = 0; 
    for (int i = 0; i < n; ++i) sum += a[i];
    int index = -1;
    for (int i = 0; i < n; ++i) 
        if (a[i]&1) index = i + 1;
    vector<bool> dp(sum + 1);
    dp[0] = true;
    for (int i = 0; i < n; ++i) {
        for (int j = sum; j >= 0; --j) {
            if (j >= a[i]) dp[j] = dp[j] || dp[j - a[i]];
        }
    }
    pi mn(20,0);
    for (int i = 0; i < n; ++i)
        mn = min(mn, (pi) make_pair(__builtin_ctz(a[i]), i + 1));
    if (sum&1) cout << 0;
    else if (index != -1) {
        if (dp[sum / 2]) cout << 1 << '\n' << index;
        else cout << 0;
    } else if (dp[sum / 2]) cout << 1 << '\n' << mn.s;
    else cout << 0;
}

signed main() {
    ios_base::sync_with_stdio(0); 
    cin.tie(0); cout.tie(0);

    int t = 1;
    if (MULTI_TEST) cin >> t;
    while (t--) solve();

    return 0;
}
