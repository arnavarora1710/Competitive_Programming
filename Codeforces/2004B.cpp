// https://codeforces.com/contest/2004/problem/B
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
int l1, l2, r1, r2;

void solve() {
    cin >> l1 >> r1 >> l2 >> r2;
    if (l1 > l2) {
        swap(l1, l2);
        swap(r1, r2);
    } else if (l1 == l2 && r1 > r2) {
        swap(r1, r2);
    }
    if (l1 == l2) cout << r1 - l1 + (r1 != r2) << '\n';
    else if (r1 == r2) cout << r2 - l2 + (l1 != l2) << '\n'; 
    else if (l2 > r1) cout << "1\n";
    else if (r2 > r1) cout << r1 - l2 + 2 << '\n';
    else cout << r2 - l2 + 2 << '\n';
}

signed main() {
    ios_base::sync_with_stdio(0); 
    cin.tie(0); cout.tie(0);

    int t = 1;
    if (MULTI_TEST) cin >> t;
    while (t--) solve();

    return 0;
}
