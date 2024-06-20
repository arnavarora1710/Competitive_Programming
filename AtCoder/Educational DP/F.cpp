#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")

#include <bits/stdc++.h>
using namespace std;

#define int long long

typedef pair<int, int> pi;
#define f first
#define s second
#define MULTI_TEST (0)
const int maxn = 3e3 + 5, inf = 1e18;
string s, t;
int dp[maxn][maxn];
pi p[maxn][maxn];

void solve() {
    cin >> s >> t;
    int n = s.size(), m = t.size();
    for (int i = 0; i < n; ++i)
	for (int j = 0; j < m; ++j) p[i][j] = {-inf, -inf};
    for (int i = 0; i < n; ++i) {
	for (int j = 0; j < m; ++j) {
	    if (s[i] == t[j]) {
		dp[i][j] = (i && j ? dp[i - 1][j - 1] : 0) + 1;
		p[i][j] = {i - 1, j - 1};
	    }
	    else { 
		int c1 = (i ? dp[i - 1][j] : 0);
		int c2 = (j ? dp[i][j - 1] : 0);
		if (!c1 && !c2) continue;
		else if (c1 > c2) {
		    dp[i][j] = c1;
		    p[i][j] = {i - 1, j}; 
		} else {
		    dp[i][j] = c2;
		    p[i][j] = {i, j - 1};
		}
	    }
	}
    }
    string ans;
    int i = n - 1, j = m - 1;
    while (i >= 0 && j >= 0) {
	if (s[i] == t[j]) ans.push_back(s[i]);
	pi ret = p[i][j];
	i = ret.f, j = ret.s;
    }
    reverse(ans.begin(), ans.end());
    cout << ans;
}

signed main () {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t = 1;
    if (MULTI_TEST) cin >> t;
    while (t--) solve();

    return 0;
}

