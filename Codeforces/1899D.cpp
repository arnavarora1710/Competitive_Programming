// https://codeforces.com/contest/1899/problem/D
#pragma GCC optimize("Ofast")
#pragma GCC optimization("unroll-loops")

#include <bits/stdc++.h>
using namespace std;

#define int long long
typedef pair<int, int> pi;
#define f first
#define s second
#define MULTI_TEST (1)
int n, a[200005];
map<long double, int> m;

int nc2(int nn) {
    if (nn < 2) return 0;
    else return (nn * (nn - 1)) / 2;
}

void solve() {
    cin >> n; m.clear();
    for (int i = 0; i < n; ++i) cin >> a[i];
    for (int i = 0; i < n; ++i) m[a[i] - log2(a[i])]++;
    int ans = 0;
    for (auto pp : m) ans += nc2(pp.s);
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