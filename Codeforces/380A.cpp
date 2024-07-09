// https://codeforces.com/contest/380/problem/A
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
int n, tp, l, c, x, q;
vector<vector<int>> a, b;
map<int, int> dp;

int calc(int ind) {
    if (dp.count(ind)) return dp[ind]; 
    int l = -1, r = b.size();
    while (r - l > 1) {
        int m = l + (r - l) / 2;
        if (b[m][0] <= ind) l = m;
        else r = m;
    }
    if (l == -1) {
        return dp[ind] = a[r][ind];
    }
    int left = b[l][0], right = left + b[l][1] * b[l][2] - 1;
    if (ind <= right) {
        return dp[ind] = calc((ind - left) % b[l][1]);
    } else {
        return dp[ind] = a[r][ind - right - 1];
    }
}

void solve() {
    cin >> n;
    a = {{}};
    int cur = 0;
    for (int i = 0; i < n; ++i) {
        cin >> tp;
        if (tp == 1) {
            cin >> x;
            cur++;
            a.back().push_back(x);
        } else {
            cin >> l >> c;
            b.push_back({cur, l, c});
            a.push_back({});
            cur += l * c;
        }
    }
    cin >> q;
    for (int i = 0; i < q; ++i) {
        int ind; cin >> ind; ind--;
        cout << calc(ind) << ' ';
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
