// https://codeforces.com/contest/1955/problem/A
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
int n, a, b;

void solve() {
    cin >> n >> a >> b;
    if (2 * a > b) {
        if (n&1) cout << n/2 * b + a << endl;
        else cout << n/2 * b << endl;
    }
    else cout << n * a << endl;
}

signed main() {
    ios_base::sync_with_stdio(0); 
    cin.tie(0); cout.tie(0);

    int t = 1;
    if (MULTI_TEST) cin >> t;
    while (t--) solve();

    return 0;
}