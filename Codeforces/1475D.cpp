#include <bits/stdc++.h>
using namespace std;

#define int long long
#define f first
#define s second
#define endl "\n"
typedef pair<int, int> pi;
const int maxn = 200005;
int n, m, one[maxn], two[maxn];
pi a[maxn]; 

void solve() {
    cin >> n >> m;
    for (int i = 0; i < n; ++i) cin >> a[i].f;
    for (int i = 0; i < n; ++i) cin >> a[i].s;
    int sum = 0; 
    for (int i = 0; i < n; ++i) sum += a[i].f;
    if (sum < m) cout << -1 << endl;
    else {
        int k1 = 0, k2 = 0;
        for (int i = 0; i < n; ++i) {
            if (a[i].s == 1) one[k1++] = a[i].f;
            else two[k2++] = a[i].f;
        }
        sort(one, one + k1, greater<int>());
        sort(two, two + k2, greater<int>());
        int i = 0, j = 0, ans = 0, cur = 0;
        while (cur < m && i < k1 && j < k2) { 
            if (cur + one[i] >= m) {
                cur += one[i]; ans++; break;
            } else if (cur + two[j] >= m) {
                cur += two[j]; ans+=2; break;
            } else if (i + 1 < k1 && one[i] + one[i + 1] > two[j]) {
                cur += one[i++]; ans++; 
            } else {
                cur += two[j++]; ans+=2; 
            }
        }
        while (i < k1 && cur < m) cur += one[i++], ans++;
        while (j < k2 && cur < m) cur += two[j++], ans+=2;
        cout << ans << endl;
    }
}

signed main() {
    int t; cin >> t;
    while (t--) solve();
}
// 1 + 1 = 2
// basically pick weight 2 only if there's no 1 + 1 to substitute it
// edge case : weight 3 (2 + 1)
// m = 5
// 3 2 1 2
// 2 1 2 1
// here, even though 2 + 2 > 3 (where 2s have weight 1 and 3 has weight 2)
// best option is to pick weight 3 (3 + 2 = 5)
