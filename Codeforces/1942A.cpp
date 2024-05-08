// https://codeforces.com/contest/1942/problem/A
#pragma GCC optimize("Ofast")
#pragma GCC optimization("unroll-loops")

#include <bits/stdc++.h>
using namespace std;

#define int long long
typedef pair<int, int> pi;
#define f first
#define s second
#define MULTI_TEST (1)
int n, k, a[200005];

void solve() {
    cin >> n >> k; 
    if (!(k == n || k == 1)) cout << -1 << endl;
    else {
    for (int i = 0; i < k; ++i) cout << 1 << " ";
    for (int i = k, kk = 2; i < n; ++i, ++kk) cout << kk << " ";
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