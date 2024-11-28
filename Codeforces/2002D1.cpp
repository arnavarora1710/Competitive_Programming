#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e5 + 5, inf = 1e18;
int n, q, x, y, p[maxn], ind[maxn], l[maxn];

void solve() {
    cin >> n >> q;
    l[1] = n;
    for (int i = 2; i <= n; ++i) {
        cin >> x;
        l[i] = l[i >> 1] >> 1;
    }
    for (int i = 1; i <= n; ++i) {
        cin >> p[i];
        ind[p[i]] = i;
    }
    while (q--) {
        cin >> x >> y;
        swap(p[x], p[y]);
        ind[p[x]] = x;
        ind[p[y]] = y;
        bool ok = 1;
        for (int i = 2; i <= n; ++i) {
            if (ind[i] < ind[i >> 1] || ind[i] >= ind[i >> 1] + l[i >> 1]) {
                cout << "NO\n";
                ok = 0;
                break;
            }
        }
        if (ok) cout << "YES\n";
    }
}

int main() {
    ios_base::sync_with_stdio(0); 
    cin.tie(0);

    int t; cin >> t;
    while (t--) solve();

    return 0;
}
