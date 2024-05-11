#pragma GCC optimize("Ofast")
#pragma GCC optimization("unroll-loops")

#include <bits/stdc++.h>
using namespace std;

#define int long long
typedef pair<int, int> pi;
#define f first
#define s second
#define MULTI_TEST (0)
const int maxn = 3e5 + 5, inf = 1e18;
int n, pr[maxn][26];
string a[maxn];

void solve() {
    cin >> n; for (int i = 0; i < n; ++i) cin >> a[i];
    sort(a, a + n);
    int ans = 0;
    for (int i = 0; i < a[0].size(); ++i) pr[i][a[0][i] - 'a']++;
    int bad = inf;
    for (int i = 1; i < n; ++i) {
        int m = a[i].size(), cur = 0;
        vector<int> res(m);
        for (int j = 0; j < m; ++j) {
            if (j == bad) {
                for (int k = 0; k < 26; ++k) pr[j][k] = 0;
                bad++;
            }
            res[j] = pr[j][a[i][j] - 'a'];
        }
        int j = 0;
        while (j < m && res[j]) j++;
        j--;
        while (j >= 0) {
            ans += (res[j] - cur) * (j + 1);
            cur = res[j];
            j--;
        }
        j = 0;
        for (; j < m; ++j) 
            if (a[i][j] != a[i - 1][j]) break;
        bad = j;
        for (int j = 0; j < m; ++j) {
            if (j == bad) {
                for (int k = 0; k < 26; ++k) pr[j][k] = 0;
                bad++;
            }
            pr[j][a[i][j] - 'a']++;
        }
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