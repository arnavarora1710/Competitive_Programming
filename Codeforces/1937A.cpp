// https://codeforces.com/contest/1937/problem/A
#pragma GCC optimize("Ofast")
#pragma GCC optimization("unroll-loops")

#include <bits/stdc++.h>
using namespace std;

#define int long long
#define MULTI_TEST (1)
int n;

int power(int a, int b) {
    int res = 1;
    while (b) {
        if (b&1) res = (res * a);
        a *= a;
        b >>= 1;
    }
    return res;
}

void solve() {
    cin >> n;
    int log = -1;
    while (n) n >>= 1, log++;
    cout << power(2, log) << endl;
}

signed main() {
    ios_base::sync_with_stdio(0); 
    cin.tie(0); cout.tie(0);

    int t = 1;
    if (MULTI_TEST) cin >> t;
    while (t--) solve();

    return 0;
}