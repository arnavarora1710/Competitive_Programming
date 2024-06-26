// https://codeforces.com/problemset/problem/1556/D
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")

#include <bits/stdc++.h>
using namespace std;

#define int long long

typedef pair<int, int> pi;
#define f first
#define s second
#define MULTI_TEST (0)
const int maxn = 2e5 + 5, inf = 1e18;
int n, k, a[maxn], done[maxn][35];

int ask(int i, int j, bool orop) {
    cout << (orop ? "or " : "and ") << i << " " << j << endl;
    int x; cin >> x;
    return x;
}

void submit(int x) {
    cout << "finish " << x << endl;
}

void solve() {
    cin >> n >> k;
    for (int i = 1; i + 1 <= n; ++i) {
        int x = ask(i, i + 1, 1), y = ask(i, i + 1, 0);
        for (int j = 0; j < 32; ++j) {
            int bitx = (x >> j)&1, bity = (y >> j)&1;
            if (bitx && bity) {
                done[i][j] = done[i + 1][j] = true;
                a[i] |= (1 << j);
                a[i + 1] |= (1 << j);
            } else if (!bitx && !bity) {
                done[i][j] = done[i + 1][j] = true;
            } else if (done[i][j]) {
                done[i + 1][j] = true;
                if (!((a[i]>>j)&1)) a[i + 1] |= (1 << j);
            }
        }
        if (i > 1) {
            bool ok = 0;
            for (int j = 0; j < 32; ++j) {
                ok |= (!done[i - 1][j] && !done[i + 1][j]);
            }
            if (ok) {
                x = ask(i - 1, i + 1, 1);
            }
            for (int j = 0; j < 32; ++j) {
                if (done[i - 1][j] && !done[i + 1][j]) {
                    done[i + 1][j] = true;
                    int bit1 = (a[i - 1] >> j)&1;
                    if (!bit1) a[i + 1] |= (1 << j);
                }
                if (done[i + 1][j] && !done[i - 1][j]) {
                    done[i - 1][j] = true;
                    int bit1 = (a[i + 1] >> j)&1;
                    if (!bit1) a[i - 1] |= (1 << j);
                }
                if (!done[i + 1][j] && !done[i - 1][j]) {
                    done[i + 1][j] = true;
                    done[i][j] = true;
                    done[i - 1][j] = true;
                    if ((x >> j)&1) {
                        a[i + 1] |= (1 << j);
                        a[i - 1] |= (1 << j);
                    } else {
                        a[i] |= (1 << j);
                    }
                }
            }
        }
    }
    sort(a + 1, a + n + 1);
    submit(a[k]);
}

signed main () {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t = 1;
    if (MULTI_TEST) cin >> t;
    while (t--) solve();

    return 0;
}
