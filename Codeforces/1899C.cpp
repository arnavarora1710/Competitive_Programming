// https://codeforces.com/contest/1899/problem/C
#pragma GCC optimize("Ofast")
#pragma GCC optimization("unroll-loops")

#include <bits/stdc++.h>
using namespace std;

#define int long long
typedef pair<int, int> pi;
#define f first
#define s second
#define MULTI_TEST (1)
int n, a[200005];

void solve() {
    cin >> n;
    for (int i = 0; i < n; ++i) cin >> a[i];
    int ans = INT_MIN;
    for (int i = 0; i < n; ++i) {
        int it = i + 1, sum = INT_MIN, cur = 0;

        bool prev = a[i]&1;
        while (it < n && ((a[it]&1) != prev))
            prev = a[it++]&1;

        int l = i, r = it - 1;
        for (int j = l; j <= r; ++j) {
            cur += a[j];
            if (sum < cur) sum = cur;
            if (cur < 0) cur = 0;
        }
        
        ans = max(ans, sum);
        i = it - 1;
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