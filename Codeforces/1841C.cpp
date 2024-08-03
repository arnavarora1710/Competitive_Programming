// https://codeforces.com/contest/1841/problem/C
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
string s;
map<int, int> m;

void solve() {
    cin >> s;
    int n = s.size();
    vector<int> a(n);
    for (int i = 0; i < n; ++i)
        a[i] = m[s[i] - 'A'];
    vector<int> suf(n), su(n);
    for (int i = n - 1; i >= 0; --i)
        suf[i] = max((i + 1 < n ? suf[i + 1] : 0), a[i]);
    for (int i = 0; i < n; ++i)
        if (suf[i] > a[i]) a[i] *= -1;
    for (int i = n - 1; i >= 0; --i) su[i] = (i + 1 < n ? su[i + 1] : 0) + a[i];
    vector<vector<int>> dp(n, vector<int>(5));
    dp[n - 1][s.back() - 'A']++;
    for (int i = n - 2; i >= 0; --i) {
        dp[i][s[i] - 'A']++;
        for (int j = 0; j < 5; ++j) dp[i][j] += dp[i + 1][j];
    }
    // mp[digit_type] -> +ve, -ve_1, -ve_2
    map<int, vector<int>> mp;
    for (int i = 0; i < 5; ++i) mp[i].resize(3);
    int ans = -inf;
    for (int i = 0; i < n; ++i) {
        int cur_val = s[i] - 'A';
        int suffix_sum = (i + 1 < n ? su[i + 1] : 0);
        // trying to change the current digit to j
        for (int j = 0; j < 5; ++j) {
            int sum = 0;
            // stuff in the prefix that is smaller than what im about to change into
            for (int k = 0; k < j; ++k) {
                sum -= (mp[k][0] + mp[k][1] + mp[k][2]) * m[k];
            }
            // stuff in the prefix that is bigger than what im about to change into 
            for (int k = cur_val - 1; k >= 0; --k) {
                if (j <= k) {
                    sum += (mp[k][0] + mp[k][1] - mp[k][2]) * m[k];
                }
            }
            for (int k = cur_val; k < 5; ++k) {
                if (j <= k) {
                    sum += (mp[k][0] - mp[k][1] - mp[k][2]) * m[k];
                }
            }
            int suffix_max = (i + 1 < n ? suf[i + 1] : 0);
            int mul = (suffix_max > m[j] ? -1 : 1);
            ans = max(ans, sum + mul * m[j] + suffix_sum);
        }
        int cnt_greater = 0;
        for (int j = cur_val + 1; j < 5; ++j)
            cnt_greater += dp[i][j];
        if (cnt_greater > 1) mp[cur_val][2]++;
        else if (cnt_greater == 1) mp[cur_val][1]++;
        else mp[cur_val][0]++;
    }
    cout << ans << '\n';
}

signed main() {
    ios_base::sync_with_stdio(0); 
    cin.tie(0); cout.tie(0);

    m[0] = 1, m[1] = 10, m[2] = 100, m[3] = 1000, m[4] = 10000;
    int t = 1;
    if (MULTI_TEST) cin >> t;
    while (t--) solve();

    return 0;
}
