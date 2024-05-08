// https://codeforces.com/contest/1915/problem/F
#pragma GCC optimize("Ofast")
#pragma GCC optimization("unroll-loops")

#include <bits/stdc++.h>
using namespace std;

#define int long long
#define f first
#define s second
typedef pair<int, int> pi;
#define MULTI_TEST (1)
const int maxn = 200005;
int n, aa, bb;
vector<pair<int, pi>> a;
vector<int> tr;
unordered_map<int, int> m;

int query(int r) {
    int ret = 0;
    for (; r >= 0; r = (r & (r + 1)) - 1)
        ret += tr[r];
    return ret;
}

void update(int idx, int delta) {
    for (; idx < 4 * maxn; idx = idx | (idx + 1))
        tr[idx] += delta;
}

void solve() {
    cin >> n; 
    a.clear(); m.clear();
    tr.clear(); tr.resize(4 * maxn);
    for (int i = 0; i < n; ++i) {
        cin >> aa >> bb;
        a.push_back({aa, {i, 1}});
        a.push_back({bb, {i, -1}}); 
    }
    sort(a.begin(), a.end());
    for (int i = 0; i < a.size(); ++i) {
        if (!m.count(a[i].s.f)) 
            a[i].s.f = m[a[i].s.f] = i + 1;
        else 
            a[i].s.f = m[a[i].s.f];
    }
    int ans = 0;
    for (int i = 0; i < a.size(); ++i) {
        if (a[i].s.s == 1) {
            update(a[i].s.f, 1);
        } else {
            update(a[i].s.f, -1);
            ans += query(a[i].s.f);
        }
    }
    cout << ans << endl;
}

signed main() {
    ios_base::sync_with_stdio(0); 
    cin.tie(0); cout.tie(0);

    int t = 1;
    if (MULTI_TEST) cin >> t;
    while (t--) solve();

    return 0;
}