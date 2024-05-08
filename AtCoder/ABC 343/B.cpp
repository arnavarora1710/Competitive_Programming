#pragma GCC optimize("Ofast")
#pragma GCC optimization("unroll-loops")

#include <bits/stdc++.h>
using namespace std;

#define int long long
#define MULTI_TEST (0)
int n, x;
vector<int> adj[105];

void solve() {
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            cin >> x;
            if (x) adj[i].push_back(j);
        }
    }   
    for (int i = 1; i <= n; ++i) {
        sort(adj[i].begin(), adj[i].end());
        for (auto nn : adj[i]) cout << nn << " ";
        cout << endl;
    }
}

signed main() {
    ios_base::sync_with_stdio(0); 
    cin.tie(0); cout.tie(0);

    int t = 1;
    if (MULTI_TEST) cin >> t;
    while (t--) solve();

    return 0;
}