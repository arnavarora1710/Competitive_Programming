#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n, m, dp[19][2][10][2];

ll rec(string s, int i, bool tight, int prev, bool placedNum) {
    if (i == s.size()) return 1;
    if (dp[i][tight][prev][placedNum] != -1) return dp[i][tight][prev][placedNum];
    int lim = tight ? (s[i] - '0') : 9;
    ll ans = 0;
    for (int dig = 0; dig <= lim; ++dig) {
        bool placed = placedNum;
        if (!placed || dig != prev) {
            if (dig) placed = true;
            if (tight && dig < (s[i] - '0')) ans += rec(s, i + 1, !tight, dig, placed);
            else ans += rec(s, i + 1, tight, dig, placed);
        }
    }
    return dp[i][tight][prev][placedNum] = ans;
}

int main() {
    cin >> n >> m; string a = to_string(n - 1), b = to_string(m);
    memset(dp, -1, sizeof(dp));
    ll upper = rec(b, 0, true, -1, false);
    memset(dp, -1, sizeof(dp));
    ll lower = rec(a, 0, true, -1, false);
    cout << upper - lower;
    return 0;
}