// https://codeforces.com/contest/1810/problem/D
#pragma GCC optimize("Ofast")
#pragma GCC optimization("unroll-loops")

#include <bits/stdc++.h>
using namespace std;

#define int long long
typedef pair<int, int> pi;
#define f first
#define s second
#define MULTI_TEST (1)
const int inf = 1e11;
int q, tp, a, b, n;

void solve() {
    cin >> q;
    int h = -1, p = -1, L = -1;
    while (q--) {
        cin >> tp;
        if (tp == 1) {
            cin >> a >> b >> n;
            int val = (n - 1) * (a - b) + a;
            if (h == -1) {
                h = val, p = val - a + (n == 1 ? 0 : b);
                L = max(L, p + 1);
                cout << 1 << ' ';
            } else {
                if (val > h) {
                    int l = 0, r = n + 1;
                    while (r - l > 1) {
                        int m = l + (r - l) / 2;
                        if (a + (m - 1) * (a - b) < h) l = m;
                        else r = m;
                    }
                    if (n > r) {
                        cout << 0 << ' ';
                    } else {
                        p = val - a + (n == 1 ? 0 : b);
                        L = max(L, p + 1);
                        cout << 1 << ' ';
                    }
                }
                else {
                    if (val >= L) {
                        h = val, p = val - a + (n == 1 ? 0 : b);
                        L = max(L, p + 1);
                        cout << 1 << ' ';
                    } else {
                        cout << 0 << ' ';
                    }
                }
            }
        } else {
            cin >> a >> b;
            if (h == -1) {
                cout << -1 << ' ';
            } else { 
                int l = 0;
                n = (h - b - 1) / (a - b) + 100;
                while (n - l > 1) {
                    int m = l + (n - l) / 2;
                    int calc = a + (m - 1) * (a - b);
                    if (calc < h) l = m;
                    else n = m; 
                }
                l = 0;
                int r = n + 1;
                while (r - l > 1) {
                    int m = l + (r - l) / 2;
                    int calc = a + (m - 1) * (a - b);
                    if (L <= calc) r = m;
                    else l = m;
                }
                if (n > r) {
                    cout << -1 << ' ';
                } else {
                    cout << n << ' ';
                }
            }
        }
    }
    cout << endl;
}

signed main() {
    ios_base::sync_with_stdio(0); 
    cin.tie(0); cout.tie(0);

    int t = 1;
    if (MULTI_TEST) cin >> t;
    while (t--) solve();

    return 0;
}