// https://codeforces.com/contest/347/problem/B
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
int n, a[maxn];

void solve() {
    cin >> n;
    for (int i = 0; i < n; ++i) cin >> a[i];
    map<int, int> cnt;
    int ans = 0;
    for (int i = 0; i < n; ++i) {
        if (a[i] != i)
            cnt[a[i]] = i;
        else ans++;
    }
    int extra = (ans != n);
    for (int i = 0; i < n; ++i) {
        if (a[i] != i) {
            int go = cnt[i];
            if (go == a[i]) {
                extra++;
                break;
            }
        }
    }
    cout << ans + extra << '\n';
}

signed main() {
    ios_base::sync_with_stdio(0); 
    cin.tie(0); cout.tie(0);

    int t = 1;
    if (MULTI_TEST) cin >> t;
    while (t--) solve();

    return 0;
}
