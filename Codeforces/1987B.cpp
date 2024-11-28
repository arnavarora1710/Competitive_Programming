// https://codeforces.com/contest/1987/problem/B
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
    int cnt = 0;
    vector<int> b;
    for (int i = 1; i < n; ++i) {
        if (a[i - 1] > a[i]) {
            b.push_back(a[i - 1] - a[i]);
            a[i] = a[i - 1];
        }
    }
    if (b.empty()) {
        cout << 0 << '\n';
    } else {
        sort(b.begin(), b.end());
        int tot = 0;
        for (int i = 0; i < b.size(); ++i) {
            b[i] -= tot;
            if (b[i]) {
                cnt += b[i] * (b.size() - i + 1);
            }
            tot += b[i];
        }
        cout << cnt << '\n';
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
