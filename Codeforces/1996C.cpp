// https://codeforces.com/contest/1996/problem/C
#pragma GCC optimize("Ofast")
#pragma GCC optimization("unroll-loops")

#include <bits/stdc++.h>
using namespace std;

#define int long long
typedef pair<int, int> pi;
#define f first
#define s second
#define mp make_pair
#define MULTI_TEST (1)
const int maxn = 2e5 + 5, inf = 1e18;
int n, q;
string a, b;

void solve() {
    cin >> n >> q >> a >> b;
    vector<vector<int>> pra(n, vector<int>(26)), prb(n, vector<int>(26));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < 26; ++j) {
            pra[i][j] = (i ? pra[i - 1][j] : 0) + (a[i] - 'a' == j);
            prb[i][j] = (i ? prb[i - 1][j] : 0) + (b[i] - 'a' == j);
        }
    }
    while (q--) {
        int l, r; cin >> l >> r; l--, r--;
        int ans = 0;
        for (int i = 0; i < 26; ++i) {
            int sum1 = pra[r][i] - (l ? pra[l - 1][i] : 0); 
            int sum2 = prb[r][i] - (l ? prb[l - 1][i] : 0);
            ans += max(0LL, sum2 - sum1);
        }
        cout << ans << '\n';
    }    
}

signed main() {
    ios_base::sync_with_stdio(0); 
    cin.tie(0); cout.tie(0);

    int t = 1;
    if (MULTI_TEST) cin >> t;
    while (t--) solve();

    return 0;
}
