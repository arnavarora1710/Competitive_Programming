#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
#pragma GCC optimization("unroll-loops")

#include <bits/stdc++.h>
using namespace std;

#define int long long
#define MULTI_TEST (1)
int n, x, s; 

void solve() {
    cin >> n; for (int i = 0; i < n; ++i) cin >> x, s += x;
    if (ceil(sqrtf(s)) == sqrt(s)) cout << "YES\n";
    else cout << "NO\n";
    s = 0;
}

signed main() {
    ios_base::sync_with_stdio(0); 
    cin.tie(0); cout.tie(0);

    int t = 1;
    if (MULTI_TEST) cin >> t;
    while (t--) solve();

    return 0;
}