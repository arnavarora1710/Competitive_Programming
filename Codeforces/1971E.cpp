// https://codeforces.com/contest/1971/problem/E
#pragma GCC optimize("Ofast")
#pragma GCC optimization("unroll-loops")

#include <bits/stdc++.h>
using namespace std;

#define int long long
typedef pair<int, int> pi;
#define f first
#define s second
#define MULTI_TEST (1)
const int maxn = 2e5 + 5, inf = 1e18;
int n, k, q, d;

void solve() {
    cin >> n >> k >> q; vector<int> a(k + 1), b(k + 1);
    a[0] = b[0] = 0;
    for (int i = 1; i <= k; ++i) cin >> a[i];
    for (int i = 1; i <= k; ++i) cin >> b[i];
    // vector<int> pra(k + 1), prb(k + 1);
    // for (int i = 0; i <= k; ++i) prb[i] = (i ? prb[i - 1] : 0) + b[i];
    // for (int i = 0; i <= k; ++i) pra[i] = (i ? pra[i - 1] : 0) + a[i];
    while (q--) {
        cin >> d;
        int index = lower_bound(a.begin(), a.end(), d) - a.begin() - 1;
        int done;
        if (index == -1) {
            done = 0;
            index = 0;
        } else {
            done = b[index];
            d -= a[index];
        }
        int time = (d * ((b[index + 1] - b[index]))) / (a[index + 1] - a[index]);
        cout << done + time << " ";
    }
    cout << endl;
}

signed main() {
    ios_base::sync_with_stdio(0); 
    cin.tie(0); cout.tie(0);

    int t = 1;
    if (MULTI_TEST) cin >> t;
    while (t--) solve();

    return 0;
}