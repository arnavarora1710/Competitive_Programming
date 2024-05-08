#pragma GCC optimize("Ofast")
#pragma GCC optimization("unroll-loops")

#include <bits/stdc++.h>
using namespace std;

#define int long long
#define MULTI_TEST (1)
const int maxn = 55;
int n, a[2 * maxn];

void solve() {
    cin >> n; for (int i = 0; i < 2 * n; ++i) cin >> a[i];
    priority_queue<int> pq;
    for (int i = 0; i < 2 * n; ++i) pq.push(a[i]);
    int ans = 0;
    while (!pq.empty()) {
        int tp = pq.top();
        pq.pop();
        tp = pq.top();
        pq.pop();
        ans += tp;
    }    
    cout << ans << endl;
}

signed main() {
    ios_base::sync_with_stdio(0); 
    cin.tie(0); cout.tie(0);

    int t = 1;
    if (MULTI_TEST) cin >> t;
    while (t--) solve();

    return 0;
}