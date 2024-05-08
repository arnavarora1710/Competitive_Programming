// https://codeforces.com/contest/1956/problem/E1
#pragma GCC optimize("Ofast")
#pragma GCC optimization("unroll-loops")

#include <bits/stdc++.h>
using namespace std;

#define int long long
typedef pair<int, int> pi;
#define f first
#define s second
#define MULTI_TEST (1)
const int maxn = 2e5 + 5, inf = 1e18;
int n, a[maxn];

void solve() {
    cin >> n; for (int i = 0; i < n; ++i) cin >> a[i];
    while (1) {
        int change = 0;
        for (int i = 0; i < n; ++i) {
            if (!a[i] && !a[(i + 3) % n] && a[(i + 1) % n] && a[(i + 2)%n]) {
                a[(i + 2) % n] = 0;
                change += (a[(i + 2) % n]);
            } else {
                int tmp = a[(i + 1) % n];
                a[(i + 1) % n] = max(0LL, a[(i + 1) % n] - a[i]);
                change += (tmp - a[(i + 1) % n]);
            }
        }
        if (!change) break;
    }
    vector<int> ans;
    for (int i = 0; i < n; ++i)
        if (a[i]) ans.push_back(i + 1);
    cout << ans.size() << endl;
    for (int i : ans) cout << i << " ";
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