#pragma GCC optimize("Ofast")
#pragma GCC optimization("unroll-loops")

#include <bits/stdc++.h>
using namespace std;

#define int long long
typedef pair<int, int> pi;
#define f first
#define s second
#define MULTI_TEST (0)
const int maxn = 2e5 + 5, inf = 1e18, mod = 998244353;
int n, a[maxn];

int power(int x, int y) {
    int res = 1;
    while (y) {
        if (y&1) res = (res * x) % mod;
        x = (x * x) % mod;
        y >>= 1;
    }
    return res;
}

int numDig(int x) {
    int cnt = 0;
    while (x) {
        cnt++;
        x /= 10;
    }
    return cnt;
}

void solve() {
    cin >> n; for (int i = 0; i < n; ++i) cin >> a[i];
    vector<vector<int>> nums(n, vector<int>(10));
    for (int i = 0; i < n; ++i) {
        for (int j = 1; j <= 10; ++j)
            nums[i][j - 1] = (a[i] * power(10, j)) % mod;
    }
    for (int i = 0; i < 10; ++i) {
        for (int j = 0; j < n; ++j)
            nums[j][i] = (nums[j][i] + (j ? nums[j - 1][i] : 0)) % mod;
    }
    // for (int i = 0; i < n; ++i) {
    //     for (int j = 0; j < 10; ++j) cerr << nums[i][j] << " ";
    //     cerr << endl;
    // }
    int ans = 0;
    for (int i = 0; i < n; ++i) {
        int dig = numDig(a[i]);
        int pr = (i ? nums[i - 1][dig - 1] : 0);
        // cerr << pr << endl;
        ans = (ans + pr) % mod;
        ans = (ans + (i * a[i]) % mod) % mod;
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