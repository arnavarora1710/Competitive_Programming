// https://codeforces.com/contest/1984/problem/A
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
    map<int, int> cnt, ind;
    for (int i = 0; i < n; ++i) cnt[a[i]]++;
    if (cnt.size() == 1) cout << "NO\n";
    else {
        cout << "YES\n";
        string ans;
        for (int i = 0; i < n; ++i) ans.push_back('.');
        int index = -1, mx = -inf;
        for (auto v : cnt) {
            if (mx < v.s) {
                mx = v.s;
                index = v.f;
            }
        }
        for (int i = 0; i < n; ++i) {
            if (a[i] == index) {
                ans[i] = 'R';
                break;
            }
        }
        for (int i = 0; i < n; ++i) {
            if (ans[i] != 'R') ans[i] = 'B';
        }
        cout << ans << '\n';
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
