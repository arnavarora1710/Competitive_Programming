// http://codeforces.com/contest/515/problem/C
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
string s;

void solve() {
    cin >> n;
    for (int i = 0; i < n; ++i) cin >> s[i];
    map<int, int> cnt;
    for (int i = 0; i < n; ++i) cnt[s[i] - '0']++;
    int val = cnt[4];
    cnt[2] += val * 2;
    cnt[3] += val;
    cnt[4] = 0;
    val = cnt[6];
    cnt[3] += val;
    cnt[5] += val;
    cnt[6] = 0;
    val = cnt[8];
    cnt[2] += val * 3;
    cnt[7] += val;
    cnt[8] = 0;
    val = cnt[9];
    cnt[9] -= val;
    cnt[3] += val * 2;
    cnt[2] += val;
    cnt[7] += val;
    for (int i = 9; i >= 2; --i) 
        for (int c = 0; c < cnt[i]; ++c) cout << i;
    cout << '\n';
}

signed main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int Q = 1; if (MULTI_TEST) cin >> Q;
    while (Q--) solve();
}