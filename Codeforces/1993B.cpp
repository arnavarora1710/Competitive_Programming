// https://codeforces.com/contest/1993/problem/B
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
    vector<int> odd, even;
    for (int i = 0; i < n; ++i) {
        if (a[i]&1) odd.push_back(a[i]);
        else even.push_back(a[i]);
    }
    sort(even.begin(), even.end());
    sort(odd.begin(), odd.end());
    if (odd.empty() || even.empty()) cout << 0 << '\n';
    else {
        int ans = 0, mx = odd.back(), i = 0, j = even.size() - 1;
        while (i <= j) {
            if (even[i] < mx) {
                mx += even[i++];
                ans++;
            } else {
                if (mx > even[j]) {
                    mx += even[j--], ans++;
                } else {
                    mx += 2 * even[j--], ans+=2;
                }
            }
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
