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
const int maxn = 505, inf = 1e18;
int n, m, k, a[maxn][maxn], schema[maxn][maxn], pr0[maxn][maxn], pr1[maxn][maxn];

int cnt0(int x1, int y1, int x2, int y2) {
    int val1 = (x1 ? pr0[x1 - 1][y2] : 0);
    int val2 = (y1 ? pr0[x2][y1 - 1] : 0);
    int val3 = (x1 && y1 ? pr0[x1 - 1][y1 - 1] : 0);
    return pr0[x2][y2] - val1 - val2 + val3;
}

int cnt1(int x1, int y1, int x2, int y2) {
    int val1 = (x1 ? pr1[x1 - 1][y2] : 0);
    int val2 = (y1 ? pr1[x2][y1 - 1] : 0);
    int val3 = (x1 && y1 ? pr1[x1 - 1][y1 - 1] : 0);
    return pr1[x2][y2] - val1 - val2 + val3;
}

void solve() {
    cin >> n >> m >> k;
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < m; ++j) cin >> a[i][j];
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            char x; cin >> x;
            schema[i][j] = x - '0';
        }
    }
    // d = s1 - s0
    int d = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            // i, j = (i - 1, j) + (i, j - 1) - (i - 1, j - 1);
            int val1 = (i ? pr0[i - 1][j] : 0);
            int val2 = (j ? pr0[i][j - 1] : 0);
            int val3 = (i && j ? pr0[i - 1][j - 1] : 0);
            pr0[i][j] = val1 + val2 - val3 + (schema[i][j] == 0);
            val1 = (i ? pr1[i - 1][j] : 0);
            val2 = (j ? pr1[i][j - 1] : 0);
            val3 = (i && j ? pr1[i - 1][j - 1] : 0);
            pr1[i][j] = val1 + val2 - val3 + (schema[i][j] == 1);
            if (schema[i][j]) d += a[i][j];
            else d -= a[i][j];
        }
    }
    int g = 0;
    for (int i = 0; i + k - 1 < n; ++i) {
        for (int j = 0; j + k - 1 < m; ++j) {
            int x1 = i, y1 = j;
            int x2 = (i + k - 1), y2 = (j + k - 1);
            int zero = cnt0(x1, y1, x2, y2);
            int one = cnt1(x1, y1, x2, y2);
            int val;
            if (d >= 0) val = (one - zero);
            else val = (zero - one);
            g = gcd(g, val);
        }
    }
    d = abs(d);
    if (!g) {
        cout << (d ? "NO\n" : "YES\n");
    } else {
        cout << (d % g ? "NO\n" : "YES\n");
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
