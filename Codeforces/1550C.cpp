// https://codeforces.com/contest/1550/problem/C
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

void solve() {
    cin >> n; vector<int> a(n);
    for (int i = 0; i < n; ++i) cin >> a[i];
    int total = n * (n + 1) / 2;
    int ans = total;
    ans -= n;
    if (n > 1) ans -= n - 1;
    if (n > 2) ans -= n - 2;
    if (n > 3) ans -= n - 3;
    for (int i = 0; i + 3 < n; ++i) {
        vector<int> b;
        for (int j = i; j <= i + 3; ++j) b.push_back(a[j]);
        for (int j = 0; j < 4; ++j) {
            for (int k = j + 1; k < 4; ++k) {
                for (int l = k + 1; l < 4; ++l) {
                    if ((b[k] >= b[j] && b[k] <= b[l]) || (b[k] <= b[j] && b[k] >= b[l])) {
                        ans++;
                        goto done;
                    }
                }
            }
        }
        done:
            continue;
    }
    for (int i = 0; i + 2 < n; ++i) {
        vector<int> b;
        for (int j = i; j <= i + 2; ++j) b.push_back(a[j]);
        for (int j = 0; j < 3; ++j) {
            for (int k = j + 1; k < 3; ++k) {
                for (int l = k + 1; l < 3; ++l) {
                    if ((b[k] >= b[j] && b[k] <= b[l]) || (b[k] <= b[j] && b[k] >= b[l])) {
                        ans++;
                        goto done1;
                    }
                }
            }
        }
        done1:
            continue;
    }
    ans = total - ans;
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
