// https://codeforces.com/contest/1981/problem/C
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")

#include <bits/stdc++.h>
using namespace std;

#define int long long

typedef pair<int, int> pi;
#define f first
#define s second
#define MULTI_TEST (1)
const int maxn = 2e5 + 5, inf = 1e18;
int n, a[maxn];

bool check() {
    for (int i = 0; i + 1 < n; ++i) {
        if (a[i] > 0) {
            int p = a[i + 1];
            if (a[i] / 2 == p || a[i] == p / 2) continue;
            else return false;
        } else return false;
    }
    return true;
}

void solve() {
    cin >> n;
    for (int i = 0; i < n; ++i) cin >> a[i];
    int first = inf, last = -inf;
    for (int i = 0; i < n; ++i) {
        if (a[i] != -1) {
            first = min(first, i);
            last = max(last, i);
            int j = i + 1;
            while (j < n && a[j] == -1) j++;
            if (j == n) {
                i = j - 1;
                break;
            }
            int x = a[i], y = a[j];
            int l = i, r = j;
            while (r - l > 1) {
                if (a[l] > a[r]) {
                    a[l + 1] = a[l] == 1 ? 2 : a[l] / 2;
                    l++;
                } else {
                    a[r - 1] = a[r] == 1 ? 2 : a[r] / 2;
                    r--;
                }
            }
            if (a[l] != a[r] / 2 && a[r] != a[l] / 2) {
                cout << -1 << "\n";
                return;
            }
            i = j - 1;
        }
    }
    if (first != inf) {
        bool flag = 1;
        int x = a[first--];
        while (first >= 0) {
            if (flag) x *= 2;
            else x /= 2;
            a[first] = x;
            flag = !flag;
            first--;
        }
        flag = 1;
        x = a[last++];
        while (last < n) {
            if (flag) x *= 2;
            else x /= 2;
            a[last] = x;
            flag = !flag;
            last++;
        }
    } else {
        a[0] = 1;
        int x = 1;
        bool flag = 1;
        for (int i = 1; i < n; ++i) {
            if (flag) x *= 2;
            else x /= 2;
            a[i] = x;
            flag = !flag;
        }
    }
    if (check()) {
        for (int i = 0; i < n; ++i) cout << a[i] << ' ';
        cout << '\n';
    } else cout << -1 << '\n';
}

signed main () {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t = 1;
    if (MULTI_TEST) cin >> t;
    while (t--) solve();

    return 0;
}
