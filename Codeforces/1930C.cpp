#pragma GCC optimize("Ofast")
#pragma GCC optimization("unroll-loops")

#include <bits/stdc++.h>
using namespace std;

#define int long long
#define f first
#define s second
#define MULTI_TEST (1)
const int maxn = 300005;
int n, a[maxn], diff[maxn];
map<int, vector<int>> dups;

void solve() {
    cin >> n; for (int i = 0; i < n; ++i) cin >> a[i];
    dups.clear();
    if (n == 1) {
        cout << a[0] + 1 << endl;
    } else {
        for (int i = 0; i < n; ++i) {
            a[i] += i + 1;
            dups[a[i]].push_back(i);
        } 

        int mx = *max_element(a, a + n);
        int smx = -1;
        for (int i = 0; i < n; ++i) {
            if (a[i] > smx && a[i] != mx) smx = a[i];
        }
        if (smx == -1) {
            cout << a[0] << " ";
            for (int i = 1; i < n; ++i) {
                a[i] -= i;   
                cout << a[i] << " ";
            }
            cout << endl;
        } else {
            if (dups[smx][0] < dups[mx][0]) smx = mx;
            for (int i = 0; i < n; ++i)
                diff[i] = (a[i] - (i ? a[i - 1] : 0));
            diff[dups[smx][0] + 1]--;
            for (int i = 1; i < n; ++i) diff[i] += diff[i - 1];

            set<int> ss(diff, diff + n);
            vector<int> ans(ss.begin(), ss.end());
            reverse(ans.begin(), ans.end());

            for (int i = 0; i < ans.size(); ++i) cout << ans[i] << " ";
            cout << endl;
        }
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