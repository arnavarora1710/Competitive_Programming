// https://codeforces.com/problemset/problem/1539/D
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAXN = 1e5;
int n; pair<ll, ll> a[MAXN];

int main() {
    cin >> n; for (int i = 0; i < n; ++i) cin >> a[i].second >> a[i].first; 
    sort(a, a + n);
    ll ans = 0, i = 0, j = n - 1, tot_red = 0;
    while (i <= j) {
        a[i].first = max(0LL, a[i].first - tot_red);
        ll need_before = a[i].first;
        tot_red += need_before + a[i].second;
        while (i < j && need_before) {
            ll pick = min(need_before, a[j].second);
            need_before -= pick;
            ans += 2 * pick;
            a[j].second = max(0LL, a[j].second - pick);
            if (need_before) --j;
        }
        if (need_before) {
            if (a[i].second >= need_before) ans += a[i].second + need_before;
            else ans += 2 * a[i].second;
        } else ans += a[i].second;
        i++;
    }
    cout << ans;
    return 0;
}