// https://codeforces.com/contest/1971/problem/F
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
int r;

int numSq(int L) {
    return sqrt(L);
}

int numSq(int L, int R) {
    return numSq(R) - numSq(L - 1);
}

void solve() {
    cin >> r;
    int ans = 0, lo = r * r, hi = (r + 1) * (r + 1);
    for (int i = 0; i <= r; ++i) {
        int val = lo - i * i, val1 = hi - i * i - 1;
        ans += numSq(val, val1);
    }
    cout << ans * 4 << endl;
}

signed main() {
    ios_base::sync_with_stdio(0); 
    cin.tie(0); cout.tie(0);

    int t = 1;
    if (MULTI_TEST) cin >> t;
    while (t--) solve();

    return 0;
}