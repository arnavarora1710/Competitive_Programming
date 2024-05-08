// https://codeforces.com/contest/1796/problem/C
#pragma GCC optimize("Ofast")
#pragma GCC optimization("unroll-loops")

#include <bits/stdc++.h>
using namespace std;

#define int long long
typedef pair<int, int> pi;
#define f first
#define s second
#define MULTI_TEST (1)
const int maxn = 2e5 + 5, mod = 998244353;
int l, r;

void solve() {
    cin >> l >> r;
    int ll = l, ans1 = 0, ans2 = 0;
    while (ll <= r) ll <<= 1, ans1++;
    int rr = r + 1; ll = l - 1;
    while (rr - ll > 1) {
        int mm = ll + (rr - ll) / 2;
        if (mm * (1 << (ans1 - 1)) <= r) ll = mm;
        else rr = mm;
    }
    ans2 = (ans2 + ll - l + 1) % mod;
    rr = r + 1, ll = l - 1;
    while (rr - ll > 1) {
        int mm = ll + (rr - ll) / 2;
        if (mm * (1 << (ans1 - 2)) * 3 <= r) ll = mm;
        else rr = mm;
    }
    ans2 = (ans2 + ((ans1 - 1) * (ll - l + 1)) % mod) % mod;
    cout << ans1 << " " << (ans2 % mod) << endl;
}

signed main() {
    ios_base::sync_with_stdio(0); 
    cin.tie(0); cout.tie(0);

    int t = 1;
    if (MULTI_TEST) cin >> t;
    while (t--) solve();

    return 0;
}