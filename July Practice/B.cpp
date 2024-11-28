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
int n, k, a[maxn];

bool check(int m) {
    int kk = k;
    for (int i = 0; i < n; ++i) {
        int sub = max(0LL, m - a[i]);
        if (kk - sub < 0) return false;
        kk -= sub;
    }
    return true;
}

bool check1() {
    for (int i = 0; i < n; ++i) {
        if (a[i] < 2) return false;
    }
    return true;
}

void solve() {
    cin >> n >> k;
    for (int i = 0; i < n; ++i) cin >> a[i];
    if (n == 1) {
        cout << a[0] + k - n + 1 << '\n';
        return;
    }
    int mx = *(max_element(a, a + n));
    int l = -1, r = mx + k + 1;
    while (r - l > 1) {
        int m = l + (r - l) / 2;
        if (check(m)) l = m;
        else r = m;
    }
    int len = l * n;
    for (int i = 0; i < n; ++i) {
        k -= max(0LL, l - a[i]);
        a[i] = max(a[i], l);
        a[i] -= l;
    }
    while (k || check1()) {
        sort(a, a + n);
        for (int i = 0; i < n; ++i) {
            if (!k || a[i] >= 2) break;
            k--, a[i]++;
        }
    }
    sort(a, a + n, greater<int>());
    for (int i = 0; i < n; ++i) {
        if (!a[i]) break;
        a[i]--, len++;
    }
    reverse(a, a + n);
    for (int i = 0; i < n; ++i) {
        if (!a[i]) break;
        a[i]--, len++;
    }
    cout << len - n + 1 << '\n';
}

signed main() {
    ios_base::sync_with_stdio(0); 
    cin.tie(0); cout.tie(0);

    int t = 1;
    if (MULTI_TEST) cin >> t;
    while (t--) solve();

    return 0;
}
