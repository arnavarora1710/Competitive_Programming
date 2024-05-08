// https://codeforces.com/contest/1792/problem/C
#pragma GCC optimize("Ofast")
#pragma GCC optimization("unroll-loops")

#include <bits/stdc++.h>
using namespace std;

#define int long long
typedef pair<int, int> pi;
#define f first
#define s second
#define MULTI_TEST (1)
const int maxn = 2e5 + 5, inf = 1e18;
int n, a[maxn];
// at the end, it has to become 1...n

bool check(int m) {
    vector<int> b;
    for (int i = 0; i < n; ++i) {
        if (a[i] > m && a[i] <= n - m) 
            b.push_back(a[i]);
    }
    for (int i = 0; i + 1 < b.size(); ++i)
        if (b[i] > b[i + 1]) return true;
    return false;
}

void solve() {
    cin >> n; for (int i = 0; i < n; ++i) cin >> a[i];
    int l = -1, r = n + 1;
    while (r - l > 1) {
        int m = l + (r - l) / 2;
        if (check(m)) l = m;
        else r = m;
    }
    cout << r << endl;
}

signed main() {
    ios_base::sync_with_stdio(0); 
    cin.tie(0); cout.tie(0);

    int t = 1;
    if (MULTI_TEST) cin >> t;
    while (t--) solve();

    return 0;
}