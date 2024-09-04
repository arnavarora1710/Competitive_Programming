// https://codeforces.com/contest/2009/problem/G1
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

template<class T> using oset = tree<T, null_type, less<T>, rb_tree_tag,tree_order_statistics_node_update>;
template<class T> using omset = tree<T, null_type, less_equal<T>, rb_tree_tag,tree_order_statistics_node_update>;

#define int long long
#define f first
#define s second
#define MULTI_TEST (1)

typedef pair<int, int> pi;
typedef vector<int> vi;
typedef vector<vector<int>> vii;

const int N = 200005, INF = 1e18, MOD = 1e9 + 7;
int n, k, q, x, y, u, v, a[N];

void solve() {
    cin >> n >> k >> q;
    for (int i = 0; i < n; ++i) cin >> a[i];
    for (int i = 0; i < n; ++i) a[i] -= i;
    map<int, int> cnt;
    set<pi> pq;
    int i = 0, j = 0;
    for (; j < k; ++j) {
        if (cnt.count(a[j])) {
            pq.erase({cnt[a[j]], a[j]});
            pq.insert({cnt[a[j]] + 1, a[j]});
        } else pq.insert({1, a[j]});
        cnt[a[j]]++;
    }
    vi ans(n);
    while (j <= n) {
        auto val = *(pq.rbegin());
        ans[i] = k - val.f;
        pq.erase({cnt[a[i]], a[i]});
        cnt[a[i]]--;
        if (!cnt[a[i]]) cnt.erase(a[i]);
        else pq.insert({cnt[a[i]], a[i]});
        if (j < n) {
            if (cnt.count(a[j])) {
                pq.erase({cnt[a[j]], a[j]});
                pq.insert({cnt[a[j]] + 1, a[j]});
            } else pq.insert({1, a[j]});
            cnt[a[j]]++;
        }
        i++;
        j++;
    }
    while (q--) {
        cin >> x >> y; x--;
        cout << ans[x] << '\n';
    }
}

signed main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int Q = 1; if (MULTI_TEST) cin >> Q;
    while (Q--) solve();
}