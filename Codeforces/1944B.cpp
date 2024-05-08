// https://codeforces.com/contest/1944/problem/B
#pragma GCC optimize("Ofast")
#pragma GCC optimization("unroll-loops")

#include <bits/stdc++.h>
using namespace std;

#define int long long
typedef pair<int, int> pi;
#define f first
#define s second
#define MULTI_TEST (1)
const int maxn = 5e4 + 5;
int n, k, a[2 * maxn];
map<int, int> m, m1;
vector<int> l, r, l1, r1;

void solve() {
    cin >> n >> k;
    m.clear(); m1.clear(); 
    l.clear(); r.clear();
    l1.clear(); r1.clear();
    for (int i = 0; i < 2 * n; ++i) cin >> a[i];
    for (int i = 0; i < n; ++i) m[a[i]]++;
    for (int i = n; i < 2 * n; ++i) m1[a[i]]++;
    for (int i = 1; i <= n; ++i) {
        if (m[i] == m1[i]) {
            l.push_back(i);
            r.push_back(i);
        } else if (m[i] == 2) {
            l1.push_back(i);
            l1.push_back(i);
        } else {
            r1.push_back(i);
            r1.push_back(i);
        }
    }
    int k1 = 0, k2 = 0;
    while (l1.size() < 2 * k) l1.push_back(l[k1++]);
    while (r1.size() < 2 * k) r1.push_back(r[k2++]);
    for (int i = 0; i < min(2 * k, (int) l1.size()); ++i) cout << l1[i] << " ";
    cout << endl;
    for (int i = 0; i < min(2 * k, (int) r1.size()); ++i) cout << r1[i] << " ";
    cout << endl;
}

signed main() {
    ios_base::sync_with_stdio(0); 
    cin.tie(0); cout.tie(0);

    int t = 1;
    if (MULTI_TEST) cin >> t;
    while (t--) solve();

    return 0;
}