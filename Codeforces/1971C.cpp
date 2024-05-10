// https://codeforces.com/contest/1971/problem/C
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

bool inb(int a, int b, int c, int d) {
    if (a > b) swap(a, b);
    if (c > d) swap(c, d);
    if ((a <= c && c <= b) && (d <= a || d >= b)) return 1;
    else if ((a <= d && d <= b) && (c <= a || c >= b)) return 1;
    else return 0;
}

void solve() {
    int a, b, c, d; cin >> a >> b >> c >> d;
    if (inb(a, b, c, d)) cout << "YES\n";
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