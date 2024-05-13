// https://codeforces.com/contest/1770/problem/C
#pragma GCC optimize("Ofast")
#pragma GCC optimization("unroll-loops")

#include <bits/stdc++.h>
using namespace std;

#define int long long
typedef pair<int, int> pi;
#define f first
#define s second
#define MULTI_TEST (1)
const int maxn = 105, inf = 1e18;
int n, a[maxn];

void solve() {
    cin >> n; for (int i = 0; i < n; ++i) cin >> a[i];
    sort(a, a + n);
    for (int i = 0; i + 1 < n; ++i) {
        if (a[i] == a[i + 1]) {
            cout << "NO\n";
            return;
        }
    }
    for (int p = 2; p <= 105; ++p) {
        vector<int> m(p);
        for (int i = 0; i < n; ++i) m[a[i] % p]++;
        if (*min_element(m.begin(), m.end()) >= 2) {
            cout << "NO\n";
            return;
        }
    }
    cout << "YES\n";
}

signed main() {
    ios_base::sync_with_stdio(0); 
    cin.tie(0); cout.tie(0);

    int t = 1;
    if (MULTI_TEST) cin >> t;
    while (t--) solve();

    return 0;
}