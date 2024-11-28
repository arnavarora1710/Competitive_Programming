// https://codeforces.com/contest/1285/problem/D
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
#define MULTI_TEST (0)

typedef pair<int, int> pi;
typedef vector<int> vi;
typedef vector<vector<int>> vii;

const int N = 200005, INF = 1e18, MOD = 1e9 + 7;
int n, k, q, x, y, u, v;

int f(vi& a, int index) {
    if (index < 0) return 0;
    if (a.size() == 0) return INF;
    vi ones, zeros;
    for (int i = 0; i < a.size(); ++i) {
        if ((a[i] >> index)&1) ones.push_back(a[i]);
        else zeros.push_back(a[i]);
    }
    return min(f(ones, index - 1), f(zeros, index - 1)) + (ones.size() && zeros.size() ? (1 << index) : 0);
}

void solve() {
    cin >> n; vi a(n);
    for (int i = 0; i < n; ++i) cin >> a[i];
    cout << f(a, 30);
}

signed main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int Q = 1; if (MULTI_TEST) cin >> Q;
    while (Q--) solve();
}