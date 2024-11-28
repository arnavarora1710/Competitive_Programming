#pragma GCC optimize("Ofast")
#pragma GCC optimization("unroll-loops")

#include <bits/stdc++.h>
using namespace std;

#define int long long
typedef pair<int, int> pi;
#define f first
#define s second
#define mp make_pair
#define MULTI_TEST (0)
const int maxn = 2e5 + 5, inf = 1e18;
int n, a[maxn];
string s, t;

void solve() {
    cin >> s >> t;
    int n = s.size(), m = t.size();
    for (int k = 1; k < n; ++k) {
        if (n / k == m || n / k == m - 1) {
            vector<string> ss(k);
            for (int i = 0; i <= (n / k); ++i) {
                // cerr << i << '\n';
                for (int j = i * k; j < min(n, (i + 1) * k); ++j) {
                    // cerr << j << ' ';
                    ss[j % k].push_back(s[j]);
                }
                // cerr << '\n';
            }
            for (string kk : ss) {
                // cerr << kk << '\n';
                if (kk == t) {
                    cout << "Yes";
                    return;
                }
            }
        }
    }
    cout << "No";
}

signed main() {
    ios_base::sync_with_stdio(0); 
    cin.tie(0); cout.tie(0);

    int t = 1;
    if (MULTI_TEST) cin >> t;
    while (t--) solve();

    return 0;
}
