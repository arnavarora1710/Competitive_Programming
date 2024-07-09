// https://codeforces.com/contest/1629/problem/D
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
string a[maxn];

void solve() {
    cin >> n;
    for (int i = 0; i < n; ++i) cin >> a[i];
    map<string, bool> m, m1;
    for (int i = n - 1; i >= 0; --i) {
        if (a[i].size() == 1) {
            cout << "YES\n";
            return;
        } else if (a[i].size() == 2) {
            string t = a[i];
            reverse(t.begin(), t.end());
            if (t == a[i] || m1.count(t)) {
                cout << "YES\n";
                return;
            }
        } else {
            string t = a[i];
            string t1 = t;
            reverse(t.begin(), t.end());
            t1.pop_back();
            reverse(t1.begin(), t1.end());
            if (t == a[i] || m.count(t) || m.count(t1)) {
                cout << "YES\n";
                return;
            }
        }
        m[a[i]] = 1;
        if (a[i].size() >= 2) {
            string t;
            int k = a[i].size() - 2;
            for (int j = 0; j < 2; ++j)
                t.push_back(a[i][k++]);
            m1[t] = 1;
        }
    }
    cout << "NO\n";
}

signed main() {
    ios_base::sync_with_stdio(0); 
    cin.tie(0); cout.tie(0);

    int t = 1;
    if (MULTI_TEST) cin >> t;
    while (t--) solve();

    return 0;
}
