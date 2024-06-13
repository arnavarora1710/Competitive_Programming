// https://codeforces.com/contest/1779/problem/D
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")

#include <bits/stdc++.h>
using namespace std;

#define int long long

typedef pair<int, int> pi;
#define f first
#define s second
#define MULTI_TEST (1)
const int maxn = 2e5 + 5, inf = 1e18;
int n, m, a[maxn], b[maxn], c[maxn];
map<int, int> need, have;
map<int, vector<int>> ind;
set<int> bounds;

void solve() {
    cin >> n;
    for (int i = 0; i < n; ++i) cin >> a[i];
    for (int i = 0; i < n; ++i) cin >> b[i];
    cin >> m;
    for (int i = 0; i < m; ++i) cin >> c[i];
    need.clear(); have.clear(); ind.clear(); bounds.clear();
    for (int i = 0; i < n; ++i) {
        if (a[i] < b[i]) {
            cout << "NO\n";
            return;
        }
    }
    for (int i = 0; i < m; ++i) have[c[i]]++;
    for (int i = 0; i < n; ++i) ind[b[i]].push_back(i);
    for (auto it = ind.rbegin(); it != ind.rend(); ++it) {
        int tot = 0;
        for (int i = 0; i < (it->s).size(); ++i) {
            int j = i + 1;
            tot++;
            bool ok = 1;
            while (j < (it->s).size()) {
                int l = (it->s)[j - 1], r = (it->s)[j];
                ok &= (a[l] == b[l]);
                auto it1 = bounds.upper_bound(l);
                if (it1 != bounds.end())
                    if (*it1 <= r)
                        break;
                j++;
            }
            if (j == (it->s).size()) {
                int index = (it->s).back();
                ok &= (a[index] == b[index]);
            }
            tot -= ok;
            i = j - 1;
        }
        need[it->f] += tot;
        for (int i = 0; i < (it->s).size(); ++i) bounds.insert((it->s)[i]);
    }
    for (auto& v : need) {
        // cerr << v.f << " : " << v.s << ' ' << have[v.f] << '\n';
        if (v.s > have[v.f]) {
            cout << "NO\n";
            return;
        }
    }
    cout << "YES\n";
}

signed main () {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t = 1;
    if (MULTI_TEST) cin >> t;
    while (t--) solve();

    return 0;
}
