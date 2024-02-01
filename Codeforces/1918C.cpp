// https://codeforces.com/contest/1918/problem/C
#pragma GCC optimize("Ofast")
#pragma GCC optimization("unroll-loops")

#include <bits/stdc++.h>
using namespace std;

#define int long long
#define MULTI_TEST (1)
int a, b, r;

int power(int a, int b) {
    int res = 1;
    while (b) {
        if (b&1) res = (res * a);
        a = (a * a);
        b >>= 1;
    }
    return res;
}

void solve() {
    cin >> a >> b >> r;
    if (a < b) swap(a, b);
    bool flag = false; 
    int cnt = 0;
    for (int i = 63; i >= 0; --i) {
        int abit = (a >> i)&1;
        int bbit = (b >> i)&1;
        if (abit && !bbit) {
            if (flag && (cnt | power(2, i)) <= r) cnt |= power(2, i); 
            flag = true;
        }
    }
    cout << (a ^ cnt) - (b ^ cnt) << endl;
}

signed main() {
    ios_base::sync_with_stdio(0); 
    cin.tie(0); cout.tie(0);

    int t = 1;
    if (MULTI_TEST) cin >> t;
    while (t--) solve();

    return 0;
}