// https://codeforces.com/contest/1551/problem/C
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
int n;
string a[maxn];

void solve() {
    cin >> n;
    for (int i = 0; i < n; ++i) cin >> a[i];
    vector<vector<int>> cnt(n, vector<int>(5));
    for (int i = 0; i < n; ++i) {
        vector<int> b(5);
        for (char c : a[i]) b[c - 'a']++;
        int sum = 0;
        for (auto v : b) sum += v;
        for (int j = 0; j < 5; ++j)
            cnt[i][j] = 2 * b[j] - sum;
    }
    int ans = 0;
    for (int i = 0; i < 5; ++i) {
        vector<int> b(n);
        for (int j = 0; j < n; ++j) b[j] = cnt[j][i];
        sort(b.begin(), b.end());
        reverse(b.begin(), b.end());
        int tot = 0, cnt1 = 0;
        for (int j = 0; j < n; ++j) {
            if (tot + b[j] <= 0) break;
            tot += b[j];
            cnt1++;
        }
        ans = max(ans, cnt1);
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
