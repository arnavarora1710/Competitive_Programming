// https://codeforces.com/contest/1798/problem/C
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
int n, a[maxn], b[maxn];

void solve() {
    cin >> n;
    for (int i = 0; i < n; ++i) cin >> a[i] >> b[i];
    int ans = 0;
    for (int i = 0; i < n; ++i) {
        int j = i, l = 1, g = 0;
        ans++;
        while (j < n) {
            g = gcd(g, a[j] * b[j]), l = lcm(l, b[j]);
            if (g % l) break;
            j++;
        }
        i = j - 1;
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