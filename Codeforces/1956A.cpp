// https://codeforces.com/contest/1956/problem/A
#pragma GCC optimize("Ofast")
#pragma GCC optimization("unroll-loops")

#include <bits/stdc++.h>
using namespace std;

#define int long long
typedef pair<int, int> pi;
#define f first
#define s second
#define MULTI_TEST (1)
const int maxn = 200, inf = 1e18;
int n, q, a[maxn], b[maxn];

void solve() {
    cin >> n >> q;
    for (int i = 0; i < n; ++i) cin >> a[i];    
    for (int i = 0; i < q; ++i) cin >> b[i];
    for (int i = 0; i < q; ++i) {
        
        // cerr << j << endl;
        cout << min(a[0] - 1, b[i]) << " ";
        // if (j >= 0) cout << a[0] - 1 << " ";
        // else cout << 1 << " ";
    }
    cout << endl;
}

signed main() {
    ios_base::sync_with_stdio(0); 
    cin.tie(0); cout.tie(0);

    int t = 1;
    if (MULTI_TEST) cin >> t;
    while (t--) solve();

    return 0;
}