// https://codeforces.com/contest/1955/problem/C
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
int n, k, a[maxn];

void solve() {
    cin >> n >> k;
    for (int i = 0; i < n; ++i) cin >> a[i];
    int ii = 0, jj = n - 1;
    int sum = 0, ans = 0;
    bool turn = 0;
    while (ii < jj) {
        if (turn) {
            if (a[ii] < a[jj]) {
                int val = 2 * a[ii];
                if (k - val < 0) break;
                k -= val;
                a[jj] -= a[ii];
                ans++, ii++;  
            } else {
                int val = 2 * a[jj] - 1;
                if (k - val < 0) break;
                k -= val;
                a[ii] -= a[jj] - 1;
                ans++, jj--;
                turn = 0;
            }
        } else {
            if (a[ii] <= a[jj]) {
                int val = 2 * a[ii] - 1;
                if (k - val < 0) break;
                k -= val;
                a[jj] -= a[ii] - 1;
                ans++, ii++;
                turn = 1;
            } else {
                int val = 2 * a[jj];
                if (k - val < 0) break;
                k -= val;
                a[ii] -= a[jj];
                ans++, jj--;
            }
        }
    }
    // while (ii < jj) {
    //     cerr << ii << " " << jj << endl;
    //     if (a[ii] < a[jj]) {
    //         if (k - 2 * a[ii] + 1 < 0) break;
    //         k -= 2 * a[ii] - 1;
    //         a[jj] -= a[ii] - 1;
    //         ans++;
    //         ii++;
    //         if (k - 1 >= 0) {
    //             a[jj]--;
    //             k--;
    //             if (a[jj] == 0) ans++, jj--;
    //         }
    //     } else if (a[ii] == a[jj]) {
    //         if (k - a[ii] < 0) break;
    //         k -= a[ii];
    //         ans++; ii++;
    //         if (k - a[jj] < 0) break;
    //         k -= a[jj];
    //         ans++; jj--;
    //     } else {
    //         if (k - 2 * a[jj] < 0) break;
    //         k -= 2 * a[jj];
    //         a[ii] -= a[jj];
    //         ans++;
    //         jj--;
    //     }
    //     cerr << k << endl;
    //     if (!k) break;
    //     // if (k - a[ii] < 0) break;
    //     // k -= a[ii];
    //     // ans++;
    //     // if (!k) break;
    //     // if (k - a[jj] < 0) break;
    //     // k -= a[jj];
    //     // ans++;
    //     // if (!k) break;
    //     // ii++, jj--;
    // }
    // cerr << endl;
    // cerr << ans << endl;
    if (ii == jj)  {
        if (k - a[ii] >= 0) 
            k -= a[ii], ans++;
    }
    cout << ans << endl;
}

signed main() {
    ios_base::sync_with_stdio(0); 
    cin.tie(0); cout.tie(0);

    int t = 1;
    if (MULTI_TEST) cin >> t;
    while (t--) solve();

    return 0;
}