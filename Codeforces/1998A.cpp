// https://codeforces.com/contest/1998/problem/A
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
int x, y, k;

void solve() {
    cin >> x >> y >> k;
    if (k&1) cout << x << ' ' << y << '\n';
    int cnt = k&1, i = 1;
    while (cnt != k) {
        cout << x - i << ' ' << y - i << '\n';
        cnt++;
        if (cnt == k) break;
        cout << x + i << ' ' << y + i << '\n';
        cnt++;
        i++;
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
