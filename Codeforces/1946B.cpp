// https://codeforces.com/contest/1946/problem/B
#pragma GCC optimize("Ofast")
#pragma GCC optimization("unroll-loops")

#include <bits/stdc++.h>
using namespace std;

#define int long long
typedef pair<int, int> pi;
#define f first
#define s second
#define MULTI_TEST (1)
const int mod = 1e9 + 7;
int n, k, a[200005];

void solve() {
    cin >> n >> k;
    for (int i = 0; i < n; ++i) cin >> a[i];
    int mx = 0, cur = 0;
    for (int i = 0; i < n; ++i) {
        cur += a[i];
        if (cur > mx) {
            mx = cur;
        }
        if (cur < 0) {
            cur = 0;
        }
    }
    int sum = 0;
    for (int i = 0; i < n; ++i) {
        sum += a[i];
    }
    int lastmx = mx;
    for (int i = 0; i < k; ++i) {
        sum = (sum + lastmx) % mod;
        lastmx = (lastmx * 2) % mod;
    }
    cout << (sum + mod) % mod << endl;
}

signed main() {
    ios_base::sync_with_stdio(0); 
    cin.tie(0); cout.tie(0);

    int t = 1;
    if (MULTI_TEST) cin >> t;
    while (t--) solve();

    return 0;
}