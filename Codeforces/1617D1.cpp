// https://codeforces.com/contest/1617/problem/D1
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")

#include <bits/stdc++.h>
using namespace std;

#define int long long

typedef pair<int, int> pi;
#define f first
#define s second
#define MULTI_TEST (1)
const int maxn = 2e5 + 5, inf = 1e18;
int n;

int ask(int x, int y, int z) {
    cout << "? " << x << " " << y << " " << z << endl;
    int ret; cin >> ret;
    return ret;
}

void solve() {
    cin >> n;
    vector<int> ret;
    for (int i = 1; i <= n - 2; ++i)
        ret.push_back(ask(i, i + 1, i + 2));
    vector<int> id(n, -1);
    int fi, la;
    for (int i = 0; i + 1 < ret.size(); ++i) {
        if (ret[i] != ret[i + 1]) {
            id[i] = ret[i], id[i + 3] = ret[i + 1];
            fi = i + 1, la = i + 4;
        }
    }
    for (int i = 0; i < n; ++i) {
        if (id[i] == -1) {
            id[i] = ask(fi, la, i + 1);
        }
    }
    int cnt = 0;
    for (int x : id) cnt += (!x);
    cout << "! " << cnt << " ";
    for (int i = 1; i <= n; ++i) 
        if (!id[i - 1]) cout << i << " ";
    cout << endl;
}

signed main () {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t = 1;
    if (MULTI_TEST) cin >> t;
    while (t--) solve();

    return 0;
}
