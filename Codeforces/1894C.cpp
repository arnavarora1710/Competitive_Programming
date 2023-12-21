// https://codeforces.com/contest/1894/problem/C
#include <bits/stdc++.h>
using namespace std;
#define int long long
const int MAXN = 200005;
int t, n, k, a[MAXN];

signed main() {
    cin >> t;
    while (t--) {
        cin >> n >> k; for (int i = 1; i <= n; ++i) cin >> a[i];
        int ptr = n; bool flag = true;
        for (int i = 0; i <= min(k - 1, n); ++i) {
            if (a[ptr] > n) flag = false;
            ptr -= a[ptr];
            if (ptr <= 0) ptr = (ceil(-ptr / (double) n) * n + ptr);
        }
        cout << (flag ? "Yes\n" : "No\n");
    }
    return 0;
}