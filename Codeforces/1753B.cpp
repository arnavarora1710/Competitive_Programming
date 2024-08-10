// https://codeforces.com/contest/1753/problem/B
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
const int maxn = 5e5 + 5, inf = 1e18;
int n, k, a[maxn];

// 1 + 1 + 2 + 2 + 2 + 2 + 2 + 2 * 3 + 2 * 3 + 2 * 3 * 4 + 2 * 3 * 4
// 2(6 + 3 + 3 + 3 * 4 + 3 * 4)
// 2(3(4(1 + 1 + 1)))
void solve() {
    cin >> n >> k;
    for (int i = 0; i < n; ++i) cin >> a[i];
    int mn = *(min_element(a, a + n));
    if (k <= mn) cout << "Yes";
    else {
        map<int, int> cnt;
        for (int i = 0; i < n; ++i) cnt[a[i]]++;
        int sum = 0;
        for (int i = mn; i < k; ++i) {
            if ((sum + cnt[i]) % (i + 1) == 0) {
                sum = (sum + cnt[i]) / (i + 1);
            } else {
                cout << "No";
                return;
            }
        }
        cout << "Yes";
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
