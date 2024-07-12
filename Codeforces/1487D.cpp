// https://codeforces.com/contest/1487/problem/D
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

// a^2 + b^2 = c^2
// a^2 = c^2 - b^2 = (c + b) (c - b)
// a^2 - b = c => a^2 = c + b
// c - b = 1
// c = b + 1
// a^2 = 2b + 1
// a = sqrt(2b + 1)
// d = 2b + 1
// b = (d - 1) / 2
// n has to be odd
// c = b + 1

void solve() {
    cin >> n;
    int ans = 0;
    for (int i = 3; ; i += 2) {
        int d = i * i;
        int b = (d - 1) / 2;
        int a = sqrt(d);
        int c = b + 1;
        if (c > n) break;
        ans++;
    }
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
