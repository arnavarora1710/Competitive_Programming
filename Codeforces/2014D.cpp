// https://codeforces.com/contest/2014/problem/D
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

const int INF = 1e18;
int n, d, k;

void solve() {
    cin >> n >> d >> k; vii inter(k, vi(2));
    for (int i = 0; i < k; ++i)
        cin >> inter[i][0] >> inter[i][1];
    vi all(n + 1), pos(n + 1);
    for (auto& z : inter) {
        all[z[0]]++, all[z[1]]--;
        pos[z[0]]++;
    }
    for (int i = 1; i <= n; ++i) 
        all[i] += all[i - 1], pos[i] += pos[i - 1];
    int mx = -INF, mn = INF;
    int id1 = -1, id2 = -1;
    for (int i = 1; i + d - 1 <= n; ++i) {
        int bef = all[i - 1];
        int bet = pos[i + d - 1] - pos[i - 1];
        if (mx < bef + bet) {
            mx = bef + bet;
            id1 = i;
        }
        if (mn > bef + bet) {
            mn = bef + bet;
            id2 = i;
        }
    }
    cout << id1 << ' ' << id2 << '\n';
}

signed main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int Q = 1; if (MULTI_TEST) cin >> Q;
    while (Q--) solve();
}