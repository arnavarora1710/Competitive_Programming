// https://codeforces.com/contest/2007/problem/D
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
string s;
vii adj;
map<char, int> cnt;

void dfs(int nn, int pp) {
    if (adj[nn].size() == 1 && pp != -1)
        cnt[s[nn]]++;
    for (auto& cc : adj[nn])
        if (cc != pp)
            dfs(cc, nn);
}

void solve() {
    cin >> n; 
    cnt.clear(); adj.clear();
    adj.resize(n + 1);
    for (int i = 0; i + 1 < n; ++i) {
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    cin >> s;
    int left = 0;
    for (char c : s) left += c == '?';
    s = "$" + s;
    dfs(1, -1);
    if (s[1] == '0') {
        cout << cnt['1'] + (cnt['?'] + 1) / 2 << '\n';
    } else if (s[1] == '1') {
        cout << cnt['0'] + (cnt['?'] + 1) / 2 << '\n';
    } else {
        int countQ = cnt['?'];
        left -= countQ + 1;
        int ans = -INF;
        if (countQ&1 && left&1) 
            ans = min(cnt['0'], cnt['1']) + (countQ + 1) / 2;
        ans = max(ans, max(cnt['0'], cnt['1']) + countQ / 2);
        cout << ans << '\n';
    }
}

signed main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int Q = 1; if (MULTI_TEST) cin >> Q;
    while (Q--) solve();
}