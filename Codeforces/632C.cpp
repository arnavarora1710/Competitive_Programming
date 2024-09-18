// https://codeforces.com/contest/632/problem/C
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")

#include <bits/stdc++.h>
using namespace std;

#define int long long

typedef pair<int, int> pi;
#define f first
#define s second
#define MULTI_TEST (0)
const int maxn = 1e5 + 5, inf = 1e18;
int n;

class Compare {
        public:
            bool cmp(string& x, string& y, int i, int j) {
                while (i < x.size() && j < y.size()) {
                    if (x[i] < y[j]) return 0;
                    else if (x[i] > y[j]) return 1;
                    i++, j++;
                }
                if (i < x.size()) return cmp(x, y, i, 0);
                else if (j < y.size()) return cmp(x, y, 0, j);
                else return 1;
            }
            bool operator()(string& x, string& y) {
                return !cmp(x, y, 0, 0);
            }
    };

void solve() {
    cin >> n; vector<string> a(n);
    for (int i = 0; i < n; ++i) cin >> a[i];
    sort(a.begin(), a.end(), Compare());
    for (string s : a) cout << s;
}

signed main () {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t = 1;
    if (MULTI_TEST) cin >> t;
    while (t--) solve();

    return 0;
}
