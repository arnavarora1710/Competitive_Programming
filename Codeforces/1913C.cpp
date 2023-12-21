// https://codeforces.com/contest/1913/problem/C
#include <bits/stdc++.h>
using namespace std;
#define int long long
int q, q1, q2, freq[30];

bool canMake() {
    for (int i = 29; i >= 0; --i) {
        int l = -1, r = freq[i] + 1;
        while (r - l > 1) {
            int m = l + (r - l) / 2;
            if (m * (1 << i) <= q2) l = m;
            else r = m; 
        }
        q2 -= min(q2, 1LL * l * (1 << i));
    }
    return !q2;
}

signed main() {
    cin >> q;
    while (q--) {
        cin >> q1 >> q2;
        if (q1 == 1) freq[q2]++;
        else cout << (canMake() ? "YES\n" : "NO\n");
    }
    return 0;
}