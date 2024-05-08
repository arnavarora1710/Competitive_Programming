// https://codeforces.com/contest/1521/problem/A
#pragma GCC optimize("Ofast")
#pragma GCC optimization("unroll-loops")

#include <bits/stdc++.h>
using namespace std;

#define int long long
typedef pair<int, int> pi;
#define f first
#define s second
#define MULTI_TEST (1)
const int maxn = 2e5 + 5, inf = 1e6 + 7;
int a, b;

void solve() {
    cin >> a >> b;
    if (b == 1) cout << "NO\n";
    else cout << "YES\n" << (2 * b - 1) * a << " " << a << " " << a * b * 2 << '\n';
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int t = 1;
    if (MULTI_TEST) cin >> t;
    while (t--) solve();

    return 0;
}
