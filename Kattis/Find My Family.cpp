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

const int N = 300005, INF = 1e18, MOD = 1e9 + 7;
int n, k, q, x, y, u, v, a[N];

void solve() {
    cin >> q;
    vi ans;
    for (int Q = 1; Q <= q; ++Q) {
        cin >> n;
        for (int i = 0; i < n; ++i) cin >> a[i];
        set<int> s;
        vi suf(n);
        for (int i = n - 1; i >= 0; --i) suf[i] = max((i + 1 < n ? suf[i + 1] : 0), a[i]);
        for (int i = 0; i + 1 < n; ++i) {
            int me = a[i], bob = suf[i + 1];
            auto lb = s.lower_bound(me);
            if (lb != s.end() && *lb <= bob) {
                ans.push_back(Q);
                break;
            }
            s.insert(me);
        }
    }
    cout << ans.size() << '\n';
    for (auto& x : ans) cout << x << '\n';
}

signed main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int Q = 1; if (MULTI_TEST) cin >> Q;
    while (Q--) solve();
}