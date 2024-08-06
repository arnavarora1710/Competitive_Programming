// https://codeforces.com/contest/1999/problem/B
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
int a1, a2, b1, b2;

void solve() {
    cin >> a1 >> a2 >> b1 >> b2;
    // a1,b1 ; a2,b2
    // a1,b2 ; a2,b1
    // a2,b1 ; a1,b2
    // a2,b2 ; a1,b1
    int ans = 0;
    ans += (a1 > b1 && a2 > b2) || (a1 == b1 && a2 > b2) || (a1 > b1 && a2 == b2);
    ans += (a1 > b2 && a2 > b1) || (a1 == b2 && a2 > b1) || (a1 > b2 && a2 == b1); 
    ans += (a2 > b1 && a1 > b2) || (a2 == b1 && a1 > b2) || (a2 > b1 && a1 == b2); 
    ans += (a2 > b2 && a1 > b1) || (a2 == b2 && a1 > b1) || (a2 > b2 && a1 == b1); 
    cout << ans << '\n';
}

signed main() {
    ios_base::sync_with_stdio(0); 
    cin.tie(0); cout.tie(0);

    int t = 1;
    if (MULTI_TEST) cin >> t;
    while (t--) solve();

    return 0;
}
