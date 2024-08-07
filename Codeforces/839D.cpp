// https://codeforces.com/contest/839/problem/D
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
const int maxm = 1e6 + 5, inf = 1e18, mod = 1e9 + 7;

void solve() {
    int N; cin >> N;
    vector<int> A(N), pw(N + 1), dp(maxm), cnt(maxm);
    for (auto& x : A) cin >> x;
    pw[0] = 1;
    for (int i = 1; i <= N; ++i) 
        pw[i] = (pw[i - 1] << 1) % mod;
    for (int i = 0; i < N; ++i) {
        for (int j = 1; j * j <= A[i]; ++j) {
            if (A[i] % j == 0) {
                int f1 = j;
                int f2 = A[i] / j;
                cnt[f1]++;
                if (f1 != f2) cnt[f2]++;
            }
        }
    }
    for (int i = 0; i < maxm; ++i) {
        dp[i] = (cnt[i] * pw[cnt[i] - 1]) % mod;
    }
    for (int i = maxm - 1; i; --i)
        for (int j = 2 * i; j < maxm; j += i)
            dp[i] = (dp[i] - dp[j] + mod) % mod;
    int ans = 0;
    for (int i = 2; i < maxm; ++i)
        ans = (ans + (i * dp[i]) % mod) % mod;
    cout << ans;
}

signed main() {
    ios_base::sync_with_stdio(0); 
    cin.tie(0); cout.tie(0);

    int t = 1;
    if (MULTI_TEST) cin >> t;
    while (t--) solve();

    return 0;
}
