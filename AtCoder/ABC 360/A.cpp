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
int n, a[maxn];
string s;

void solve() {
    cin >> s;
    int idr, idm;
    for (int i = 0; i < 3; ++i) {
        if (s[i] == 'R') idr = i;
        if (s[i] == 'M') idm = i;
    }
    cout << (idr < idm ? "Yes" : "No");
}

signed main() {
    ios_base::sync_with_stdio(0); 
    cin.tie(0); cout.tie(0);

    int t = 1;
    if (MULTI_TEST) cin >> t;
    while (t--) solve();

    return 0;
}