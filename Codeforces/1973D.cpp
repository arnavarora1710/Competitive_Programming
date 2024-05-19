// https://codeforces.com/contest/1973/problem/D
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

void ask(int& r, int l, int x) {
    cout << "? " << l << " " << x << endl;
    cin >> r;
}

bool submit(int ans) {
    cout << "! " << ans << endl;
    int x; cin >> x;
    return (x == -1 ? 0 : 1);
}

void solve() {
    cin >> n >> k;
    int mx;
    for (int i = 1; i <= n; ++i) {
        int ans;
        ask(ans, 1, n * i);
        if (ans == n) mx = i;
    }
    int fin_ans = -1;
    for (int i = 1; i <= n / k; ++i) {
        int j = 1, kk = k;
        while (j <= n && kk--) {
            int ans;
            ask(ans, j, i * mx);
            if (ans == n + 1) break;
            j = ans + 1;
        }
        if (j == n + 1 && !kk) fin_ans = i * mx;
    }
    submit(fin_ans);
}

signed main() {
    ios_base::sync_with_stdio(0); 
    cin.tie(0); cout.tie(0);

    int t = 1;
    if (MULTI_TEST) cin >> t;
    while (t--) solve();

    return 0;
}
