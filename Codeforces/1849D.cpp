// https://codeforces.com/contest/1849/problem/D
#pragma GCC optimize("Ofast")
#pragma GCC optimization("unroll-loops")

#include <bits/stdc++.h>
using namespace std;

#define int long long
typedef pair<int, int> pi;
#define f first
#define s second
#define MULTI_TEST (0)
const int maxn = 2e5 + 5, inf = 1e18;
int n, a[maxn];

void solve() {
    cin >> n; for (int i = 0; i < n; ++i) cin >> a[i];
    int ans = 0;
    for (int i = 0; i < n;) {
        int j = i + 1;
        bool two = (a[i] == 2);
        while (j < n) {
            if (j - i > 1 && !a[j - 1]) break;
            if (a[j] == 2) two = 1;
            bool ok;
            if (two) ok = 1;
            else if (a[i] || a[j]) ok = 1;
            else ok = 0;
            if (!ok) break;
            j++;
        } 
        i = j;
        ans++;
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