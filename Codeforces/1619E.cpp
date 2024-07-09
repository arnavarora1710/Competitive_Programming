// https://codeforces.com/contest/1619/problem/E
#pragma GCC optimize("Ofast")
#pragma GCC optimization("unroll-loops")

#include <bits/stdc++.h>
using namespace std;

#define int long long
typedef pair<int, int> pi;
#define f first
#define s second
#define mp make_pair
#define MULTI_TEST (1)
const int maxn = 2e5 + 5, inf = 1e18;
int n, a[maxn];

void solve() {
    cin >> n;
    for (int i = 0; i < n; ++i) cin >> a[i];
    vector<int> b(n + 2);
    for (int i = 0; i < n; ++i) b[a[i]]++;
    bool ok = 1;
    int mex;
    priority_queue<pi> pq;
    for (int i = 0; i <= n; ++i) {
        if (b[i]) {
            if (b[i] > 1) pq.push({i, b[i] - 1});
            cout << b[i] << ' ';
        } else { 
            cout << 0 << ' ';
            mex = i;
            break;
        }
    }
    // fill till i - 1 and vacate i
    int p = 0;
    vector<bool> filled(n + 2);
    for (int i = mex + 1; i <= n; ++i) {
        if (pq.empty()) {
            if (filled[i - 1]) {
                int val = p + b[i];
                if (b[i]) filled[i] = true;
                if (b[i] > 1) pq.push({i, b[i] - 1});
                cout << val << ' ';
                p = val - b[i];
            } else cout << -1 << ' ';
        } else {
            pi tp = pq.top(); pq.pop();
            int val = (filled[i - 1] ? 0 : i - 1 - tp.f);
            val += p + b[i];
            if (b[i]) filled[i] = true;
            if (b[i] > 1) pq.push({i, b[i] - 1});
            cout << val << ' ';
            if (!filled[i - 1]) tp.s--;
            if (tp.s) pq.push(tp);
            p = val - b[i];
        }
    }
    cout << '\n';
}

signed main() {
    ios_base::sync_with_stdio(0); 
    cin.tie(0); cout.tie(0);

    int t = 1;
    if (MULTI_TEST) cin >> t;
    while (t--) solve();

    return 0;
}
