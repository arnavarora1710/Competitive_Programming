#pragma GCC optimize("Ofast")
#pragma GCC optimization("unroll-loops")

#include <bits/stdc++.h>
using namespace std;

#define int long long
typedef pair<int, int> pi;
#define f first
#define s second
#define mp make_pair
#define MULTI_TEST (0)
const int maxn = 2e5 + 5, inf = 1e18;
int a[12];

void solve() {
    for (int i = 0; i < 12; ++i) cin >> a[i];
    for (int i = 0; i < 3; ++i) {
        int x = max(a[i], a[i + 6]);
        int y = min(a[i + 3], a[i + 9]);
        if (x >= y) {
            cout << "No\n";
            return;
        }
    }
    cout << "Yes";
}

signed main() {
    ios_base::sync_with_stdio(0); 
    cin.tie(0); cout.tie(0);

    int t = 1;
    if (MULTI_TEST) cin >> t;
    while (t--) solve();

    return 0;
}
