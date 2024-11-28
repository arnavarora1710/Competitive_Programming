// https://codeforces.com/contest/1995/problem/A
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
int n, k;

void solve() {
    cin >> n >> k;
    if (!k) cout << 0 << '\n';
    else if (k <= n) cout << 1 << '\n';
    else {
        k -= n;
        int cnt = n - 1;
        int ans = 1;
        while (1) {
            ans++;
            k = max(0LL, k - cnt);
            if (!k) break;
            ans++;
            k = max(0LL, k - cnt);
            if (!k) break;
            cnt--;
        }
        cout << ans << '\n';
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
