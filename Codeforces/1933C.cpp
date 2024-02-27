// https://codeforces.com/contest/1933/problem/C
#pragma GCC optimize("Ofast")
#pragma GCC optimization("unroll-loops")

#include <bits/stdc++.h>
using namespace std;

#define int long long
#define MULTI_TEST (1)
int a, b, l;

int power(int xx, int yy) {
    int res = 1;
    while (yy) {
        if (yy&1) res *= xx;
        xx *= xx;
        yy >>= 1;
    }
    return res;
}

void solve() {
    cin >> a >> b >> l;
    set<int> kk;
    for (int i = 0; i <= 1e2; ++i) {
        if (power(a, i) > l) break;
        for (int j = 0; j <= 1e2; ++j) {
            if (power(b, j) > l) break;
            if (power(a, i) * power(b, j) > l) break;
            if (l % (power(a, i) * power(b, j)) == 0)
                kk.insert(l / (power(a, i) * power(b, j)));
        }
    }
    cout << kk.size() << endl;
}

signed main() {
    ios_base::sync_with_stdio(0); 
    cin.tie(0); cout.tie(0);

    int t = 1;
    if (MULTI_TEST) cin >> t;
    while (t--) solve();

    return 0;
}