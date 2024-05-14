// https://codeforces.com/problemset/problem/1511/B
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
int a, b, c;

int power(int x, int y) {
    int res = 1;
    while (y) {
        if (y&1) res *= x;
        x *= x;
        y >>= 1;
    }
    return res;
}

int dig(int x) {
    int cnt = 0;
    while (x) {
        cnt++;
        x /= 10;
    }
    return cnt;
}

void solve() {
    cin >> a >> b >> c;
    int x, y;
    x = y = power(10, c - 1);
    while (dig(x) != a) x *= 2;
    while (dig(y) != b) y *= 3;
    cout << x << ' ' << y << '\n';
}

signed main() {
    ios_base::sync_with_stdio(0); 
    cin.tie(0); cout.tie(0);

    int t = 1;
    if (MULTI_TEST) cin >> t;
    while (t--) solve();

    return 0;
}