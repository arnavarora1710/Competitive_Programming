// https://codeforces.com/contest/1930/problem/C
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
const int maxn = 3e5 + 5, inf = 1e18;
int n, a[maxn];

void solve() {
    cin >> n;
    for (int i = 1; i <= n; ++i) cin >> a[i];
    for (int i = 1; i <= n; ++i) a[i] += i;
    sort(a + 1, a + n + 1);
    set<int> b, m;
    for (int i = 1; i <= n; ++i) {
        if (a[i] == a[i - 1]) {
            b.erase(a[i - 1]);
            a[i - 1] = *(m.rbegin());
            m.erase(*(m.rbegin()));
            b.insert(a[i - 1]);
            if (b.find(a[i - 1] - 1) == b.end()) {
                m.insert(a[i - 1] - 1);
            }
        }
        if (b.find(a[i] - 1) == b.end())
            m.insert(a[i] - 1);
        b.insert(a[i]);
    }
    sort(a + 1, a + n + 1);
    for (int i = n; i; --i) cout << a[i] << ' ';
    cout << '\n';
}

signed main() {
    ios_base::sync_with_stdio(0); 
    cin.tie(0); cout.tie(0);

    int t = 1;
    if (MULTI_TEST) cin >> t;
    while (t--) solve();

    return 0;
}
