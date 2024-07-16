#pragma GCC optimize("Ofast")
#pragma GCC optimization("unroll-loops")

#include <bits/stdc++.h>
using namespace std;

#define int long long
typedef pair<int, int> pi;
#define f first
#define s second
#define mp make_pair
#define MULTI_TEST (0)
const int maxn = 2e5 + 5, inf = 1e18;
int n, x, y;
vector<vector<int>> a;

bool cmp(vector<int>& x, vector<int>& y) {
    if (x[0] == y[0]) return x[1] > y[1];
    else return x[0] < y[0];
}

void solve() {
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> x >> y;
        a.push_back({x, 1, i});
        a.push_back({y, -1, i});
    }
    sort(a.begin(), a.end(), cmp);
    vector<int> ans(n);
    set<int> notused;
    int mx = 0;
    for (int i = 1; i <= n; ++i) notused.insert(i);
    for (int i = 0; i < a.size(); ++i) {
        int pt = a[i][0], dir = a[i][1], ind = a[i][2];
        if (dir == 1) {
            int use = *(notused.begin());
            ans[ind] = use;
            mx = max(mx, use);
            notused.erase(notused.begin());
        } else {
            int used = ans[ind];
            notused.insert(used);
        }
    }
    cout << mx << '\n';
    for (int i : ans) cout << i << ' ';
}

signed main() {
    ios_base::sync_with_stdio(0); 
    cin.tie(0); cout.tie(0);

    int t = 1;
    if (MULTI_TEST) cin >> t;
    while (t--) solve();

    return 0;
}
