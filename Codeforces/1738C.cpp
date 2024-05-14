// https://codeforces.com/contest/1738/problem/C
#pragma GCC optimize("Ofast")
#pragma GCC optimization("unroll-loops")

#include <bits/stdc++.h>
using namespace std;

#define int long long
typedef pair<int, int> pi;
#define f first
#define s second
#define MULTI_TEST (1)
const int maxn = 105, inf = 1e18;
int n, a[maxn];

void submit(bool alice) {
    cout << (alice ? "Alice\n" : "Bob\n");
}

void solve() {
    cin >> n; for (int i = 0; i < n; ++i) cin >> a[i];

    int odd = 0;
    for (int i = 0; i < n; ++i) {
        a[i] = abs(a[i]);
        odd += (a[i] % 2);
    }
    int even = n - odd;

    if (odd % 4 == 2) submit(0);
    else if (odd % 4 == 3) submit(1);
    else if (odd % 4 == 0) submit(1);
    else submit(even&1);
}

signed main() {
    ios_base::sync_with_stdio(0); 
    cin.tie(0); cout.tie(0);

    int t = 1;
    if (MULTI_TEST) cin >> t;
    while (t--) solve();

    return 0;
}