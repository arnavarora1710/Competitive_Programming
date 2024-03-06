// https://codeforces.com/problemset/problem/1542/B
#pragma GCC optimize("Ofast")
#pragma GCC optimization("unroll-loops")

#include <bits/stdc++.h>
using namespace std;

#define int long long
#define MULTI_TEST (1)
int n, a, b;

void submit(bool yes) {
    cout << (yes ? "Yes\n" : "No\n");
}

int power(int x, int y, int mod) {
    int res = 1;
    while (y) {
        if (y&1) res = (res * x) % mod;
        x = (x * x) % mod;
        y >>= 1;
    }
    return res;
}

void solve() {
    cin >> n >> a >> b;
    int rem = n % b;
    for (int i = 0; i <= 100; ++i) {
        if (pow(a, i) > n) break;
        int pw = power(a, i, b);
        int modded = rem - pw;
        if (modded < 0) modded += b;
        if (!modded) {
            submit(1);
            return;
        }
    }
    submit(0);
}

signed main() {
    ios_base::sync_with_stdio(0); 
    cin.tie(0); cout.tie(0);

    int t = 1;
    if (MULTI_TEST) cin >> t;
    while (t--) solve();

    return 0;
}