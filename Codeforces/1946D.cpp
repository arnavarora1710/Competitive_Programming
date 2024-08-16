// https://codeforces.com/contest/1946/problem/D
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
int n, k, a[maxn];

int mergeIntervals(set<pi>& s) {
    vector<pi> b(s.begin(), s.end());
    vector<pi> c;
    c.push_back(b[0]);
    int j = 0;
    for (int i = 1; i < b.size(); ++i) {
        if (c[j].s >= b[i].f) 
            c[j].s = max(c[j].s, b[i].s);
        else {
            j++;
            c.push_back(b[i]);
        }
    }
    set<pi> res(c.begin(), c.end());
    s = res;
    return res.size();
}

void solve() {
    cin >> n >> k;
    for (int i = 0; i < n; ++i) cin >> a[i];
    int o = 0;
    for (int i = 0; i < n; ++i) o = o | a[i];
    if (o <= k) cout << n << '\n';
    else {
        vector<set<pi>> inter(32);
        vector<int> cnt(32);
        for (int i = 0; i < 32; ++i) {
            for (int j = 0; j < n; ++j) {
                cnt[i] += (a[j] >> i)&1;
            }
            for (int j = 0; j < n; ++j) {
                if ((a[j] >> i)&1) {
                    int x = j + 1;
                    while (x < n && !((a[x] >> i)&1)) x++;
                    inter[i].insert({j, x});
                    j = x;
                } else inter[i].insert({j, j});
            }
        }
        set<pi> master;
        int i = 31;
        for (; i >= 0; --i) {
            if ((k>>i)&1) break;
            if (cnt[i]) {
                if (cnt[i]&1) {
                    cout << -1 << '\n';
                    return;
                } else {
                    for (auto& v : inter[i]) 
                        master.insert(v);
                }
            }
        }
        if (!master.empty()) mergeIntervals(master);
        int ans = -1;
        for (; i >= 0; --i) {
            if (cnt[i]) {
                if ((k>>i)&1) {
                    if (cnt[i] % 2 == 0) {
                        set<pi> tmp = master;
                        for (auto& v : inter[i])
                            tmp.insert(v);
                        ans = max(ans, mergeIntervals(tmp));
                    }
                } else break;
            } else {
                if ((k >> i) & 1) {
                    cout << mergeIntervals(master) << '\n';
                    return;
                }
            }
        }
        bool ok = 1;
        for (; i >= 0; --i) {
            if ((k >> i)&1 && !cnt[i]) break;
            if (!((k >> i)&1) && cnt[i]) {
                if (cnt[i]&1) {
                    ok = 0;
                    break;
                }
                for (auto& v : inter[i])
                    master.insert(v);
            }
            if ((k >> i)&1 && cnt[i]) {
                if (cnt[i] % 2 == 0) {
                    set<pi> tmp = master;
                    for (auto& v : inter[i])
                        tmp.insert(v);
                    ans = max(ans, mergeIntervals(tmp));
                }
            }
        }
        if (ok) 
            ans = max(ans, mergeIntervals(master));
        cout << ans << '\n';
    }
}

signed main() {
    ios_base::sync_with_stdio(0); 
    cin.tie(0); cout.tie(0);

    int t = 1;
    if (MULTI_TEST) cin >> t;
    while (t--) solve();

    return 0;
}
