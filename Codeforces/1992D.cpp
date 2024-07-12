// https://codeforces.com/contest/1992/problem/D
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
int n, m, k;
string s;

void solve() {
    cin >> n >> m >> k;
    s.clear(); s.push_back('L');
    for (int i = 0; i < n; ++i) {
        char x; cin >> x;
        s.push_back(x);
    }
    n++;
    int i = 0;
    while (i < n) {
        if (s[i] == 'L') {
            if (i + m >= n) {
                cout << "YES\n";
                return;
            }
            bool ok = 0;
            for (int j = i + m; j > i; --j) {
                if (s[j] == 'L') {
                    i = j;
                    ok = 1;
                    break;
                }
            }
            if (ok) continue;
            i += m;
        } else if (s[i] == 'W') {
            if (!k) {
                cout << "NO\n";
                return;
            }
            k--, i++;
        } else {
            cout << "NO\n";
            return;
        }
    }     
    cout << "YES\n";
}

signed main() {
    ios_base::sync_with_stdio(0); 
    cin.tie(0); cout.tie(0);

    int t = 1;
    if (MULTI_TEST) cin >> t;
    while (t--) solve();

    return 0;
}
