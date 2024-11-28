// https://codeforces.com/contest/1857/problem/F
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
    cin >> n;
    for (int i = 0; i < n; ++i) cin >> a[i];
    map<int, int> cnt;
    for (int i = 0; i < n; ++i) cnt[a[i]]++;
    cin >> q;
    while (q--) {
        cin >> x >> y;
        int sq = sqrt(x * x - 4 * y);
        if (sq * sq != x * x - 4 * y) cout << 0 << ' ';
        else {
            set<multiset<int>> s;
            int val1 = x + sq, val2 = x - sq;
            if (val1 % 2 == 0 && y % (val1 / 2) == 0) s.insert({val1 / 2, y / (val1 / 2)});
            if (val2 % 2 == 0 && y % (val2 / 2) == 0) s.insert({val2 / 2, y / (val2 / 2)});
            int ans = 0;
            for (auto& Z : s) {
                pi z = {*(Z.begin()), *(Z.rbegin())};
                if (z.f != z.s) ans += (cnt[z.f] * cnt[z.s]);
                else ans += (cnt[z.f] * (cnt[z.f] - 1)) / 2;
            }
            cout << ans << ' ';
        }
    }
    cout << '\n';
}

signed main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int Q = 1; if (MULTI_TEST) cin >> Q;
    while (Q--) solve();
}