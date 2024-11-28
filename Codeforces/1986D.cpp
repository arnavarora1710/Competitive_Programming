// https://codeforces.com/contest/1986/problem/D
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
int n;
string s;

int best(int i, int j) {
    return min(i * j, i + j);
}

void solve() {
    cin >> n >> s;
    if (n == 2) {
        cout << stoll(s) << '\n';
        return;
    }
    int ans = inf;
    for (int i = 0; i + 1 < n; ++i) {
        int res = 0, p = -1;
        for (int j = 0; j < n; ++j) {
            if (j == i) {
                if (p == -1) {
                    res = (s[j] - '0') * 10 + s[j + 1] - '0';
                }
                else res = best(p, (s[j] - '0') * 10 + s[j + 1] - '0');
                j++;
            } else {
                if (p == -1) res = s[j] - '0';
                else res = best(p, s[j] - '0');
            }
            p = res;
        }
        ans = min(ans, res);
    }
    cout << ans << '\n';
}

signed main() {
    ios_base::sync_with_stdio(0); 
    cin.tie(0); cout.tie(0);

    int t = 1;
    if (MULTI_TEST) cin >> t;
    while (t--) solve();

    return 0;
}
