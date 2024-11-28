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
int n, m;

void solve() {
    cin >> n >> m;
    if (!((n&1 && m&1) || (!(n&1) && !(m&1)))) {
        cout << 0 << '\n';
        return;
    }
    map<int, int> ans;
    for (int i = 1; i * i <= (n - m)>>1; ++i) {
        if (((n - m)>>1) % i == 0) {
            int f1 = i, f2 = ((n - m)>>1) / i;
            if (f1 + 1 >= m) ans[f1 + 1] = f2;
            if (f2 + 1 >= m) ans[f2 + 1] = f1;
        }
    }
    for (int i = 1; i * i <= (n + m - 2)>>1; ++i) {
        if (((n + m - 2)>>1) % i == 0) {
            int f1 = i, f2 = ((n + m - 2)>>1) / i;
            if (f1 + 1 >= m) ans[f1 + 1] = f2 - 1;
            if (f2 + 1 >= m) ans[f2 + 1] = f1 - 1;
        }
    }
    cout << ans.size() << '\n';
}

signed main() {
    ios_base::sync_with_stdio(0); 
    cin.tie(0); cout.tie(0);

    int t = 1;
    if (MULTI_TEST) cin >> t;
    while (t--) solve();

    return 0;
}
