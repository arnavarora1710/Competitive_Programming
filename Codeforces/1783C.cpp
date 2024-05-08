// https://codeforces.com/contest/1783/problem/C
#pragma GCC optimize("Ofast")
#pragma GCC optimization("unroll-loops")

#include <bits/stdc++.h>
using namespace std;

#define int long long
typedef pair<int, int> pi;
#define f first
#define s second
#define MULTI_TEST (1)
const int maxn = 5e5 + 5, inf = 1e18;
int n, m, a[maxn];

bool check(int mm) {
    vector<int> c(a, a + n);
    c.erase(c.begin() + mm);
    sort(c.begin(), c.end());
    int cnt = 1, cnt1 = 0;
    int tmp = m, tmp1 = m;
    if (tmp - a[mm] < 0) cnt = -1;
    else tmp -= a[mm];
    for (int i = 0; i < n - 1; ++i) {
        if (cnt != -1 && tmp - c[i] >= 0) {
            cnt++;
            tmp -= c[i];
        }
        if (tmp1 - c[i] >= 0) {
            cnt1++;
            tmp1 -= c[i];
        }
    }
    return cnt >= mm || cnt1 >= mm + 1;
}

void solve() {
    cin >> n >> m;
    for (int i = 0; i < n; ++i) cin >> a[i];
    int l = -1, r = n;
    while (r - l > 1) {
        int mm = l + (r - l) / 2;
        if (check(mm)) l = mm;
        else r = mm;
    }
    cout << n - l << endl;
}

signed main() {
    ios_base::sync_with_stdio(0); 
    cin.tie(0); cout.tie(0);

    int t = 1;
    if (MULTI_TEST) cin >> t;
    while (t--) solve();

    return 0;
}