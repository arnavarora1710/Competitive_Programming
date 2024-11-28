// https://codeforces.com/contest/1990/problem/A
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
int n, a[maxn];

void solve() {
    cin >> n;
    for (int i = 0; i < n; ++i) cin >> a[i];
    int mx = 0;
    map<int, int> ct;
    for (int i = 0; i < n; ++i) mx = max(mx, a[i]), ct[a[i]]++;
    int cnt = 0;
    for (int i = 0; i < n; ++i) cnt += (a[i] == mx);
    if (cnt&1) cout << "YES\n";
    else {
        for (auto& v : ct) {
            if (v.s&1) {
                cout << "YES\n";
                return;
            }
        }
        cout << "NO\n";
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
