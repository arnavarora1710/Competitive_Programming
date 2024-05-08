// https://codeforces.com/contest/1759/problem/E
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
int n, h, a[maxn];

int calc(int blue) {
    int use1 = 1, use2 = 1, use3 = 1;
    int ans = 0, i = 0, hh = h;
    while (i < n) {
        if (a[i] < hh) hh += a[i++] / 2, ans++;
        else if (use1) {
            if (blue == 1) hh *= 3;
            else hh *= 2;
            use1--;
        } else if (use2) {
            if (blue == 2) hh *= 3;
            else hh *= 2;
            use2--;
        } else if (use3) {
            if (blue == 3) hh *= 3;
            else hh *= 2;
            use3--;
        } else break;
    }
    return ans;
}

int max(int x, int y, int z) {
    return max(x, max(y, z));
}

void solve() {
    cin >> n >> h; for (int i = 0; i < n; ++i) cin >> a[i];
    sort(a, a + n);
    cout << max(calc(1), calc(2), calc(3)) << endl;
}

signed main() {
    ios_base::sync_with_stdio(0); 
    cin.tie(0); cout.tie(0);

    int t = 1;
    if (MULTI_TEST) cin >> t;
    while (t--) solve();

    return 0;
}