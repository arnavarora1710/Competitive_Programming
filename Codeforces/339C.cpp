// https://codeforces.com/contest/339/problem/C
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")

#include <bits/stdc++.h>
using namespace std;

#define int long long

typedef pair<int, int> pi;
#define f first
#define s second
#define MULTI_TEST (0)
const int maxn = 2e3 + 5, inf = 1e18;
int n;
pair<int, pi> dp[maxn][15][15];
string s;

void solve() {
    cin >> s >> n;
    set<int> use;
    for (int i = 1; i <= 10; ++i) {
        if (s[i - 1] == '1') use.insert(i);
    }
    for (int i : use) {
        dp[1][i][i] = {true, {-1, -1}};
    }
    for (int i = 2; i <= n; ++i) {
        for (int j : use) {
            for (int k = 1; k <= 10; ++k) {
                if (j - k > 0) {
                    for (int l : use) {
                        if (l != j) {
                            dp[i][j][k].f |= dp[i - 1][l][j - k].f;
                            if (dp[i - 1][l][j - k].f) {
                                dp[i][j][k].s = {l, j - k};
                            }
                        }
                    }
                }
            }
        }
    }
    for (int i = 1; i <= 10; ++i) {
        for (int j = 1; j <= 10; ++j) {
            if (dp[n][i][j].f) {
                cout << "YES\n";
                vector<int> res;
                while (dp[n][i][j].s.f != -1) {
                    res.push_back(i);
                    pi ret = dp[n][i][j].s;
                    i = ret.f;
                    j = ret.s;
                    n--;
                }
                res.push_back(i);
                reverse(res.begin(), res.end());
                for (int k : res) cout << k << ' ';
                return;
            }
        }
    }
    cout << "NO\n";
}

signed main () {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t = 1;
    if (MULTI_TEST) cin >> t;
    while (t--) solve();

    return 0;
}
