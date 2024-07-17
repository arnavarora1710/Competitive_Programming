// https://codeforces.com/contest/1928/problem/B
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
int n, a[maxn];

void solve() {
    cin >> n;
    for (int i = 0; i < n; ++i) cin >> a[i];
    set<int> s(a, a + n); vector<int> b(s.begin(), s.end());
    int ans = 0;
    for (int i = 0; i < b.size(); ++i) {
        int l = -1, r = i, cnt = 0;
        while (r - l > 1) {
            int m = l + (r - l) / 2;
            if (b[i] - b[m] < n) r = m;
            else l = m;
        }
        cnt += i - l;
        ans = max(ans, cnt);
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