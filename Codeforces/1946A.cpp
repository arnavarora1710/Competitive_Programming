// https://codeforces.com/contest/1946/problem/A
#pragma GCC optimize("Ofast")
#pragma GCC optimization("unroll-loops")

#include <bits/stdc++.h>
using namespace std;

#define int long long
typedef pair<int, int> pi;
#define f first
#define s second
#define MULTI_TEST (1)
int n, x, y, a[200005];

void solve() {
    cin >> n;
    for (int i = 0; i < n; ++i) cin >> a[i];
    if (n == 1) cout << 1 << endl;
    else {
        sort(a, a + n);
        int med = a[(n + 1) / 2 - 1], cnt = 0;
        for (int i = (n + 1) / 2 - 1; i < n; ++i)
            if (a[i] == med) cnt++;
        cout << cnt << endl;
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