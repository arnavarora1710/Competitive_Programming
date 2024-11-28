// https://codeforces.com/contest/1986/problem/C
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
string s, t;

void solve() {
    cin >> n >> m >> s;
    for (int i = 0; i < m; ++i) cin >> a[i];
    cin >> t;
    sort(a, a + m);
    sort(t.begin(), t.end());
    int i = 0, j = m - 1;
    for (int k = 0; k < m; ++k) {
        int kk = k + 1;
        while (kk < m && a[kk] == a[k]) kk++, j--;
        s[a[k] - 1] = t[i++];
        k = kk - 1;
    }    
    cout << s << '\n';
}

signed main() {
    ios_base::sync_with_stdio(0); 
    cin.tie(0); cout.tie(0);

    int t = 1;
    if (MULTI_TEST) cin >> t;
    while (t--) solve();

    return 0;
}
