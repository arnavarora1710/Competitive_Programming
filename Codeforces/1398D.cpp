// https://codeforces.com/problemset/problem/1398/D
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")

#include <bits/stdc++.h>
using namespace std;

#define int long long

typedef pair<int, int> pi;
#define f first
#define s second
#define MULTI_TEST (0)
const int maxn = 2e2 + 5, inf = 1e18;
int R, G, B, a[maxn], b[maxn], c[maxn], dp[maxn][maxn][maxn];

int max(vector<int>& A) {
    return *(max_element(A.begin(), A.end()));
}

void solve() {
    cin >> R >> G >> B;
    for (int i = 1; i <= R; ++i) cin >> a[i];
    for (int i = 1; i <= G; ++i) cin >> b[i];
    for (int i = 1; i <= B; ++i) cin >> c[i];
    sort(a + 1, a + R + 1);
    sort(b + 1, b + G + 1);
    sort(c + 1, c + B + 1);
    for (int i = 0; i <= R; ++i) {
        for (int j = 0; j <= G; ++j) {
            for (int k = 0; k <= B; ++k) {
                vector<int> A = {(i ? dp[i - 1][j][k] : 0), (j ? dp[i][j - 1][k] : 0), (k ? dp[i][j][k - 1] : 0),
                                (i && j ? dp[i - 1][j - 1][k] : 0) + a[i] * b[j],
                                (i && k ? dp[i - 1][j][k - 1] : 0) + a[i] * c[k],
                                (j && k ? dp[i][j - 1][k - 1] : 0) + b[j] * c[k]};
                dp[i][j][k] = max(A);
            }
        }
    }
    cout << dp[R][G][B];
}

signed main () {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t = 1;
    if (MULTI_TEST) cin >> t;
    while (t--) solve();

    return 0;
}
