// https://codeforces.com/contest/1547/problem/E
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
const int maxn = 3e5 + 5, inf = 1e18;
int n, k, a[maxn], t[maxn];

// tj + |aj - i|
// = tj + aj - i or tj - aj + i
// for all aj > i  for all aj < i
// maybe store a list of tj + aj and a list of tj - aj
// so for all aj that are lesser than i / greater than i use respectively
// prefix / suffix minm

void solve() {
    cin >> n >> k;
    for (int i = 0; i < k; ++i) cin >> a[i];
    for (int i = 0; i < k; ++i) cin >> t[i];
    vector<pi> vl, vr;
    for (int i = 0; i < k; ++i) vl.push_back({a[i], t[i] - a[i]});
    for (int i = 0; i < k; ++i) vr.push_back({a[i], t[i] + a[i]});
    sort(vl.begin(), vl.end());
    sort(vr.begin(), vr.end());
    for (int i = 1; i < k; ++i) vl[i].s = min(vl[i].s, vl[i - 1].s);
    for (int i = k - 2; i >= 0; --i) vr[i].s = min(vr[i].s, vr[i + 1].s);
    for (int i = 1; i <= n; ++i) {
        int l = -1, r = k;
        while (r - l > 1) {
            int m = l + (r - l) / 2;
            if (vl[m].f <= i) l = m;
            else r = m;
        }
        int mnleft = (l == -1 ? inf : vl[l].s + i);
        int mnright = (r == k ? inf : vr[r].s - i);
        cout << min(mnleft, mnright) << ' ';
    }
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
