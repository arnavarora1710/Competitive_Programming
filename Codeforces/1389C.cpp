// https://codeforces.com/contest/1389/problem/C
#pragma GCC optimize("Ofast")
#pragma GCC optimization("unroll-loops")

#include <bits/stdc++.h>
using namespace std;

#define int long long
#define f first
#define s second
#define mp make_pair
#define MULTI_TEST (1)
const int maxn = 2e5 + 5, inf = 1e18;
string s;

// 12345
// 23451
// 51234

// 123456
// 234561
// 612345

// if length is odd, everything has to be equal
// otherwise, alternate have to be equal

// 2 = 4 = 6
// 1 = 3 = 5

// 2 = 5, 2 = 4, 1 = 4, 1 = 3, 3 = 5
// 1 = 2 = 3 = 4 = 5
// 1212121

void solve() {
    cin >> s;
    int n = s.size();
    vector<vector<int>> ind(10);
    for (int i = 0; i < n; ++i)
        ind[s[i] - '0'].push_back(i);
    int ans = inf;
    for (int i = 0; i <= 9; ++i) {
        for (int j = 0; j <= 9; ++j) {
            int ii = 0, jj = 0, tot = 0;
            int pi = -1, pj = -1;
            bool turn = 1;
            while (ii < ind[i].size() && jj < ind[j].size()) {
                if (turn) {
                    while (ii < ind[i].size() && ind[i][ii] <= pj)
                        ii++;
                    if (ii < ind[i].size()) {
                        tot++;
                        pi = ind[i][ii];
                    }
                } else {
                    while (jj < ind[j].size() && ind[j][jj] <= pi)
                        jj++;
                    if (jj < ind[j].size()) {
                        tot++;
                        pj = ind[j][jj];
                    }
                }
                turn = !turn;
            }
            tot -= (i != j && (tot&1));
            ans = min(ans, n - tot);
        }
    }
    cout << ans << '\n';
}

signed main() {
    ios_base::sync_with_stdio(0); 
    cin.tie(0); cout.tie(0);

    int t = 1;
    if (MULTI_TEST) cin >> t;
    while (t--) solve();

    return 0;
}
