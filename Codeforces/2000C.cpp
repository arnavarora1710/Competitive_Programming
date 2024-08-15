// https://codeforces.com/contest/2000/problem/C
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
int n, m, a[maxn];
string s;

void solve() {
    cin >> n;
    for (int i = 0; i < n; ++i) cin >> a[i];
    cin >> m;
    for (int i = 0; i < m; ++i) {
        cin >> s;
        if (s.size() != n) {
            cout << "NO\n";
        } else {
            map<char, int> m1;
            map<int, char> m2;
            for (int i = 0; i < n; ++i) {
                if (m1.count(s[i])) {
                    if (m1[s[i]] != a[i]) {
                        cout << "NO\n";
                        goto done;
                    }
                }
                else m1[s[i]] = a[i];
            }
            for (int i = 0; i < n; ++i) {
                if (m2.count(a[i])) {
                    if (m2[a[i]] != s[i]) {
                        cout << "NO\n";
                        goto done;
                    }
                } else m2[a[i]] = s[i];
            }
            cout << "YES\n";
            done:
                continue;
        }
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
