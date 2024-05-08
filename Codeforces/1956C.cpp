// https://codeforces.com/contest/1956/problem/C
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
// i know how to do the operations optimally
// how it ends
// 1) unwind it
// 2) build it

void solve() {
    cin >> n;
    vector<vector<int>> a(n, vector<int>(n));
    int cnt = n;
    for (int i = 0; i < n; ++i) {
        for (int j = i; j < n; ++j) 
            a[i][j] = cnt;
        for (int j = i; j < n; ++j)
            a[j][i] = cnt;
        cnt--;
    }
    int sum = 0;
    for (int i = 0; i < n; ++i) 
        for (int j = 0; j < n; ++j) sum += a[i][j];
    cout << sum << " " << 2 * n << endl;
    for (int i = 1; i <= n; ++i) {
        cout << 1 << " " << i << " ";
        if (i != 1) 
            for (int j = 1; j <= n; ++j) cout << j << " ";
        else 
            for (int j = n; j >= 1; --j) cout << j << " ";
        cout << endl;
        cout << 2 << " " << n - i + 1 << " ";
        for (int j = n; j >= 1; --j) cout << j << " ";
        cout << endl;
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