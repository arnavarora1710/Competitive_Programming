#pragma GCC optimize("Ofast")
#pragma GCC optimization("unroll-loops")

#include <bits/stdc++.h>
using namespace std;

#define int long long
typedef pair<int, int> pi;
#define f first
#define s second
#define MULTI_TEST (0)
int n, k, a[200005];

void solve() {
    cin >> n >> k;
    for (int i = 0; i < n; ++i) cin >> a[i];
    int sum = (k * (k + 1)) / 2;
    map<int, int> done;
    for (int i = 0; i < n; ++i) {
        if (!done[a[i]] && a[i] <= k) {
            done[a[i]] = 1;
            sum -= a[i];
        }
    }
    cout << sum;
}

signed main() {
    ios_base::sync_with_stdio(0); 
    cin.tie(0); cout.tie(0);

    int t = 1;
    if (MULTI_TEST) cin >> t;
    while (t--) solve();

    return 0;
}