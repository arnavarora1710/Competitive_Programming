// https://codeforces.com/contest/1534/problem/D
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")

#include <bits/stdc++.h>
using namespace std;

#define int long long

typedef pair<int, int> pi;
#define f first
#define s second
#define MULTI_TEST (0)
const int maxn = 2e5 + 5, inf = 1e18;
int n, vis[maxn];
set<set<int>> ans;

vector<int> ask(int x) {
    cout << "? " << x << endl;
    vector<int> ret(n);
    for (int i = 0; i < n; ++i) cin >> ret[i];
    return ret;
}

void bfs() {
    queue<int> q;
    q.push(1); vis[1] = true;
    while (!q.empty()) {
        int tp = q.front(); q.pop();
        vector<int> ret = ask(tp);
        int odd = 0, even = 0;
        for (int i = 1; i <= n; ++i) {
            if (!vis[i]) {
                if (ret[i - 1]&1) odd++;
                else even++;
            }
        }
        if (odd > even) {
            for (int i = 1; i <= n; ++i) {
                if (ret[i - 1] == 1) ans.insert({tp, i});
                if (!vis[i] && ret[i - 1] % 2 == 0) {
                    q.push(i);
                    vis[i] = true;
                }
            }
        } else {
            for (int i = 1; i <= n; ++i) {
                if (ret[i - 1] == 1) ans.insert({tp, i});
                if (!vis[i] && ret[i - 1]&1) {
                    q.push(i);
                    vis[i] = true;
                }
            }
        }
    }
}

void solve() {
    cin >> n;
    bfs();
    cout << "!" << endl;
    for (auto v : ans) {
        for (auto w : v) cout << w << ' ';
        cout << endl;
    }
}

signed main () {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t = 1;
    if (MULTI_TEST) cin >> t;
    while (t--) solve();

    return 0;
}
