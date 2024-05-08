#pragma GCC optimize("Ofast")
#pragma GCC optimization("unroll-loops")

#include <bits/stdc++.h>
using namespace std;

#define int long long
typedef pair<int, int> pi;
#define f first
#define s second
#define MULTI_TEST (0)
int h, w, q, tp, xx, yy;
map<int, pi> r, c;
map<int, int> ans;

void solve() {
    cin >> h >> w >> q;
    for (int i = 0; i < q; ++i) {
        cin >> tp >> xx >> yy;
        if (tp == 1) r[xx] = {yy, i};
        else c[xx] = {yy, i};
    }
    vector<int> rr, cc;
    for (auto& row : r) rr.push_back(row.s.s);
    for (auto& col : c) cc.push_back(col.s.s);
    sort(rr.begin(), rr.end());
    sort(cc.begin(), cc.end());
    for (auto& row : r) {
        int idx = lower_bound(cc.begin(), cc.end(), row.s.s) - cc.begin();
        idx = cc.size() - idx;
        ans[row.s.f] += w - idx;
    }
    for (auto& col : c) {
        int idx = lower_bound(rr.begin(), rr.end(), col.s.s) - rr.begin();
        idx = rr.size() - idx;
        ans[col.s.f] += h - idx;
    }
    int sum = 0, sz = 0;
    for (auto& res : ans)
        sum += res.s;
    sum = h * w - sum;
    ans[0] += sum;
    for (auto& res : ans) 
        if (res.s) sz++;
    cout << sz << endl;
    for (auto& res : ans)
        if (res.s)
            cout << res.f << " " << res.s << endl;
}

signed main() {
    ios_base::sync_with_stdio(0); 
    cin.tie(0); cout.tie(0);

    int t = 1;
    if (MULTI_TEST) cin >> t;
    while (t--) solve();

    return 0;
}