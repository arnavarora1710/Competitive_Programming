// https://codeforces.com/contest/2009/problem/E
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

int sum(int l, int r) {
    return max(0LL, (r * (r + 1)) / 2 - (l * (l - 1)) / 2);
}

void solve() {
    cin >> n >> k;
    int l = k, r = k + n;
    while (r - l > 1) {
        int m = l + (r - l) / 2;
        if (sum(k, m) - sum(m + 1, k + n - 1) < 0) l = m;
        else r = m;
    }
    cout << min(sum(k, r) - sum(r + 1, k + n - 1), - sum(k, l) + sum(r, k + n - 1)) << '\n';
}

signed main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int Q = 1; if (MULTI_TEST) cin >> Q;
    while (Q--) solve();
}