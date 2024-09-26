// https://codeforces.com/contest/2005/problem/C
#include <bits/stdc++.h>
using namespace std;

#define MULTI_TEST (1)

const int N = 1005, INF = 1e9, MOD = 1e9 + 7;
int n, m, q, x, y, u, v, dp[N][5], precomp[N][5][4];
string A, a[N];

void solve() {
    cin >> n >> m;
    // store 5 * things taken, things left, things started but didnt finish
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        for (int j = 0; j < 5; ++j) {
            dp[i][j] = -INF;
            int taken = 0, left = 0, st = j;
            bool ok = (j == 0);
            for (int k = 0; k < m; ++k) {
                if (a[i][k] == A[st]) {
                    if (st == 4) {
                        if (ok) taken++;
                        else ok = 1;
                    }
                    st = (st + 1) % 5;
                } else if (a[i][k] == 'n' || a[i][k] == 'a' 
                            || a[i][k] == 'r' || a[i][k] == 'e' 
                            || a[i][k] == 'k') left++;
            }
            precomp[i][j][0] = 5 * taken;
            precomp[i][j][1] = left;
            precomp[i][j][2] = st;
            precomp[i][j][3] = ok;
        }
    }
    for (int i = 0; i < n; ++i) dp[i][0] = 0;
    int i = 0;
    while (i < n) {
        if (find(a[i].begin(), a[i].end(), 'n') != a[i].end()) {
            int taken = precomp[i][0][0];
            int left = precomp[i][0][1];
            int val = precomp[i][0][2];
            int ok = precomp[i][0][3];
            for (int kk = 0; kk <= val; ++kk)
                dp[i][kk] = max(dp[i][kk], taken - left + kk - val);
            i++; break;
        }
        i++;
    }
    for (; i < n; ++i) {
        for (int j = 0; j < 5; ++j)
            dp[i][j] = dp[i - 1][j];
        for (int l = 0; l < 5; ++l) {
            int taken = precomp[i][l][0];
            int left = precomp[i][l][1];
            int val = precomp[i][l][2];
            int ok = precomp[i][l][3];
            int extra = (l && ok ? 5 : 0);
            for (int kk = 0; kk <= val; ++kk) {
                dp[i][kk] = max(dp[i][kk], dp[i - 1][l] + extra + taken - left + kk - val);
            }
        }
    }
    cout << dp[n - 1][0] << '\n';
}

signed main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    A = "narek";
    int Q = 1; if (MULTI_TEST) cin >> Q;
    while (Q--) solve();
}