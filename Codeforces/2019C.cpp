// https://codeforces.com/contest/2019/problem/C
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
    cin >> n >> k;
    for (int i = 1; i <= n; ++i) cin >> a[i];
    sort(a + 1, a + n + 1);
    reverse(a + 1, a + n + 1);
    vi s(n + 1);
    for (int i = n; i >= 1; --i) s[i] = (i + 1 <= n ? s[i + 1] : 0) + a[i];
    int sum = s[1];
    for (int d = n; d >= 2; --d) {
        int K = (d - (sum % d));
        int oldK = K % d;
        if (oldK <= k) {
            if ((d - 1) * a[1] <= s[2] + oldK) {
                cout << d << '\n';
                return;
            }
            K = oldK + ((k - oldK) / d) * d;
            if ((d - 1) * a[1] <= s[2] + K) {
                cout << d << '\n';
                return;
            }
        }
    }
    cout << 1 << '\n';
}

signed main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int Q = 1; if (MULTI_TEST) cin >> Q;
    while (Q--) solve();
}