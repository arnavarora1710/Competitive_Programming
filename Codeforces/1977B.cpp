// https://codeforces.com/contest/1977/problem/B
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
int x;

void solve() {
    cin >> x;
    vector<int> a(32);
    int j = 0;
    while (x) {
        if (x&1) a[j] = 1;
        j++;
        x >>= 1;
    }
    while (true) {
        bool ok = 1;
        for (int i = 31; i > 0; --i) {
            if (a[i] == -1 && a[i - 1] == 1) {
                a[i - 1] = -1; 
                a[i] = 0;
                ok = 0;
            } else if (a[i] == 1 && a[i - 1] == 1) {
                a[i + 1] = 1;
                a[i - 1] = -1;
                a[i] = 0;
                ok = 0;
            }
        }
        if (ok) break;
    }
    cout << 32 << '\n';
    for (int i : a) cout << i << ' ';
    cout << '\n';
}

signed main() {
    ios_base::sync_with_stdio(0); 
    cin.tie(0); cout.tie(0);

    int t = 1;
    if (MULTI_TEST) cin >> t;
    while (t--) solve();

    return 0;
}
