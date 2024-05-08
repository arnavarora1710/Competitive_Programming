// https://codeforces.com/contest/1814/problem/B
#pragma GCC optimize("Ofast")
#pragma GCC optimization("unroll-loops")

#include <bits/stdc++.h>
using namespace std;

#define int long long
typedef pair<int, int> pi;
#define f first
#define s second
#define MULTI_TEST (1)
const int inf = 1e18;
int a, b;

int calc(int n, int m, int i) {
    return (n + i - 1) / i + (m + i - 1) / i + i - 1;
}

void solve() {
    cin >> a >> b;
    int mn = a + b;
    for (int i = 1; i <= 1e5; ++i)
        mn = min(mn, calc(a, b, i));
    cout << mn << endl;
}

signed main() {
    ios_base::sync_with_stdio(0); 
    cin.tie(0); cout.tie(0);

    int t = 1;
    if (MULTI_TEST) cin >> t;
    while (t--) solve();

    return 0;
}