// https://codeforces.com/contest/1537/problem/D
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

void solve() {
    cin >> n;
    int lg = log2(n);
    if (n&1) cout << "Bob\n";
    else if (n&(n - 1)) cout << "Alice\n";
    else if (lg&1) cout << "Bob\n";
    else cout << "Alice\n";
}

signed main() {
    ios_base::sync_with_stdio(0); 
    cin.tie(0); cout.tie(0);

    int t = 1;
    if (MULTI_TEST) cin >> t;
    while (t--) solve();

    return 0;
}
