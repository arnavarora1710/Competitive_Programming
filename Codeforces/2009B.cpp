// https://codeforces.com/contest/2009/problem/B
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
int n, k, q, x, y, u, v;
char a, b, c, d;

void solve() {
    cin >> n;
    vi ans;
    for (int i = 0; i < n; ++i) {
        cin >> a >> b >> c >> d;
        if (a == '#') ans.push_back(1);
        else if (b == '#') ans.push_back(2);
        else if (c == '#') ans.push_back(3);
        else ans.push_back(4);
    }
    reverse(ans.begin(), ans.end());
    for (auto& x : ans) cout << x << ' ';
    cout << '\n';
}

signed main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int Q = 1; if (MULTI_TEST) cin >> Q;
    while (Q--) solve();
}