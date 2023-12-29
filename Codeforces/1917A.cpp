// https://codeforces.com/problemset/problem/1917/A
#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
#pragma GCC optimization("unroll-loops")

#include <bits/stdc++.h>
using namespace std;

#define int long long
#define MULTI_TEST (1)
int n, a[100];

void solve() {
    cin >> n; for (int i = 0; i < n; ++i) cin >> a[i];
    int cnt = 0, prd = 1, idx = 1, flag = 0;
    for (int i = 0; i < n; ++i) {
        prd *= a[i];
        if (a[i] < 0) cnt++, idx = i;
        else if (a[i] == 0) flag = 1;
    }
    if (cnt&1 || flag) cout << 0 << endl;
    else {
        cout << 1 << endl << idx << " " << 0 << endl;    
    }
}

signed main() {
    ios_base::sync_with_stdio(0); 
    cin.tie(0); cout.tie(0);

    int t = 1;
    if (MULTI_TEST) cin >> t;
    while (t--) solve();

    return 0;
}