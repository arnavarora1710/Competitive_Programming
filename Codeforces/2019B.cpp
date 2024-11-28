// https://codeforces.com/contest/2019/problem/B
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
    cin >> n >> q;
    for (int i = 1; i <= n; ++i) cin >> a[i];
    map<int, int> mp;
    for (int i = 1; i <= n; ++i) {
        int val = n - i + (i - 1) * (n - i + 1);
        mp[n - i + (i - 1) * (n - i + 1)]++;
        if (i + 1 <= n) {
            mp[(n - i) * i] += a[i + 1] - a[i] - 1;
        }
    }
    while (q--) {
        cin >> k;
        cout << mp[k] << ' ';
    }
    cout << '\n';
}

signed main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int Q = 1; if (MULTI_TEST) cin >> Q;
    while (Q--) solve();
}