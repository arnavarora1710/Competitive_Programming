// https://codeforces.com/contest/1848/problem/C
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
const int maxn = 2e5 + 5, inf = 1e18;
int n, a[maxn], b[maxn];

void solve() {
    cin >> n;
    for (int i = 0; i < n; ++i) cin >> a[i];
    for (int i = 0; i < n; ++i) cin >> b[i];
    bool oka = 1, okb = 1;
    for (int i = 0; i < n; ++i) {
        if (a[i]) oka = 0;
        if (b[i]) okb = 0;
    }
    if (oka || okb) {
        cout << "YES\n";
        return;
    }
    int oo = 0, oe = 0, eo = 0;
    for (int i = 0; i < n; ++i) {
        if (!a[i] && !b[i]) continue;
        int g = gcd(a[i], b[i]);
        a[i] /= g;
        b[i] /= g;
        oo += (a[i]&1 && b[i]&1);
        oe += (a[i]&1 && !(b[i]&1));
        eo += (!(a[i]&1) && b[i]&1);
    }
    if ((oo && !oe && !eo) || (!oo && oe && !eo) || (!oo && !oe && eo)) cout << "YES\n";
    else if (oe && eo) cout << "NO\n";
    else cout << "NO\n";
}

signed main() {
    ios_base::sync_with_stdio(0); 
    cin.tie(0); cout.tie(0);

    int t = 1;
    if (MULTI_TEST) cin >> t;
    while (t--) solve();

    return 0;
}
