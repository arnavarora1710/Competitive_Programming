// https://codeforces.com/contest/2007/problem/C
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
    cin >> n >> x >> y;
    for (int i = 0; i < n; ++i) cin >> a[i];
    int g = gcd(x, y);
    map<int, int> mp;
    for (int i = 0; i < n; ++i) mp[a[i] % g]++;
    vi ans;
    for (auto& u : mp) ans.push_back(u.f);
    int mn = INF;
    for (int i = 0; i < ans.size(); ++i)
        mn = min({mn, max(ans.back() - ans[i], (i ? (ans[i - 1] - ans[i] + g) % g : -INF))});
    cout << mn << '\n';
}

signed main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int Q = 1; if (MULTI_TEST) cin >> Q;
    while (Q--) solve();
}