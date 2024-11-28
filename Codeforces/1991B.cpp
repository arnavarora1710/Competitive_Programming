// https://codeforces.com/contest/1991/problem/B
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
    for (int i = 0; i + 1 < n; ++i) cin >> a[i];
    vector<int> b(n);
    b[0] = a[0];
    for (int i = 1; i + 1 < n; ++i) 
        b[i] = a[i] | a[i - 1];
    b[n - 1] = a[n - 2];
    for (int i = 0; i + 1 < n; ++i) {
        if ((b[i] & b[i + 1]) != a[i]) {
            cout << -1 << '\n';
            return;
        }
    }
    for (auto& x : b) cout << x << ' ';
    cout << '\n';    
}

signed main() {
    ios_base::sync_with_stdio(0); 
    cin.tie(0); cout.tie(0);

    int t = 1;
    if (MULTI_TEST) cin >> t;
    while (t--) solve();

    return 0;
}
