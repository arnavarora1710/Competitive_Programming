// https://codeforces.com/contest/1992/problem/F
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
    cin >> n >> x;
    for (int i = 0; i < n; ++i) cin >> a[i];
    vi ind;
    for (int i = 0; i < n; ++i)
        if (a[i] != 1 && x % a[i] == 0)
            ind.push_back(i);
    int ans = 1;
    for (int i = 0; i < ind.size(); ++i) {
        int j = i + 1;
        unordered_map<int, bool> dp, dp1;
        dp[a[ind[i]]] = dp1[a[ind[i]]] = true;
        while (j < ind.size()) {
            int need = x / a[ind[j]];
            if (dp.count(need)) {
                ans++;
                break;
            }
            for (auto& y : dp) {
                if (x % (y.f * a[ind[j]]) == 0) 
                    dp1[y.f * a[ind[j]]] = true;
            }
            dp1[a[ind[j]]] = true;
            dp = dp1;
            j++;
        }
        i = j - 1;
    }
    cout << ans << '\n';
}

signed main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int Q = 1; if (MULTI_TEST) cin >> Q;
    while (Q--) solve();
}