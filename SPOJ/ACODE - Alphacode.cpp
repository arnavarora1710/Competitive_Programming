#pragma GCC optimize("Ofast")
#pragma GCC optimization("unroll-loops")

#include <bits/stdc++.h>
using namespace std;

#define int long long
typedef pair<int, int> pi;
#define f first
#define s second
#define mp make_pair
#define MULTI_TEST (0)
const int maxn = 2e5 + 5, inf = 1e18;
string s;

void solve() {
    while (1) {
        cin >> s;
        if (s == "0") break;
        int n = s.size();
        s = "#" + s;
        vector<int> dp(n + 1);
        dp[0] = 1;
        for (int i = 1; i <= n; ++i) {
            dp[i] = (s[i] == '0' ? 0 : dp[i - 1]);
            if (s[i - 1] == '1' || (s[i - 1] == '2' && s[i] <= '6'))
                dp[i] += (i >= 2 ? dp[i - 2] : 0);
        }
        cout << dp.back() << '\n';
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
