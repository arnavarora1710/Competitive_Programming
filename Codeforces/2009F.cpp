// https://codeforces.com/contest/2009/problem/F
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
int n, k, q, x, y, u, v, a[N], p[N], s[N];

int sum(int shift, int l, int r) {
    shift = n - shift;
    l = (l - shift + n) % n;
    r = (r - shift + n) % n;
    if (l <= r) return p[r] - (l ? p[l - 1] : 0);
    else return s[l] + p[r];
}

void solve() {
    cin >> n >> q;
    for (int i = 0; i < n; ++i) cin >> a[i];
    for (int i = 0; i < n; ++i)
        p[i] = (i ? p[i - 1] : 0) + a[i];
    for (int i = n - 1; i >= 0; --i)
        s[i] = (i + 1 < n ? s[i + 1] : 0) + a[i];
    while (q--) {
        cin >> x >> y;
        x--, y--;
        int id1 = x / n, id2 = y / n;
        if (id1 == id2) {
            cout << sum(id1, x % n, y % n) << '\n';
        } else {
            int tot = id2 - id1 - 1;
            tot *= p[n - 1];
            tot += sum(id1, x % n, n - 1);
            tot += sum(id2, 0, y % n);
            cout << tot << '\n';
        }
    }
}

signed main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int Q = 1; if (MULTI_TEST) cin >> Q;
    while (Q--) solve();
}