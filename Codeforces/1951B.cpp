// https://codeforces.com/contest/1951/problem/B
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
int n, k, a[maxn];

void solve() {
    cin >> n >> k;
    for (int i = 0; i < n; ++i) cin >> a[i];
    --k;
    int newK, ans = 0;
    for (int i = 0; i < n; ++i) {
        if (a[i] > a[k]) {
            ans += (i > 0);
            swap(a[i], a[k]);
            newK = i;
            break;
        } else if (a[i] == a[k]) {
            swap(a[0], a[k]);
            newK = 0;
            break;
        }
    }
    for (int i = newK + 1; i < n; ++i) {
        if (a[i] < a[newK]) ans++;
        else break;
    }
    cout << max(newK - 1, ans) << endl;
}

signed main() {
    ios_base::sync_with_stdio(0); 
    cin.tie(0); cout.tie(0);

    int t = 1;
    if (MULTI_TEST) cin >> t;
    while (t--) solve();

    return 0;
}