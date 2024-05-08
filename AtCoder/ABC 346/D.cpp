#pragma GCC optimize("Ofast")
#pragma GCC optimization("unroll-loops")

#include <bits/stdc++.h>
using namespace std;

#define int long long
typedef pair<int, int> pi;
#define f first
#define s second
#define MULTI_TEST (0)
int n, a[200005];
string s;

void solve() {
    cin >> n >> s;
    for (int i = 0; i < n; ++i) cin >> a[i];
    vector<int> pr1(n), pr2(n);
    // pr1 = 010101
    // pr2 = 101010
    bool z1 = 1, z2 = 0;
    for (int i = 0; i < n; ++i) {
        if (!z1) pr1[i] = (i ? pr1[i - 1] : 0) + (s[i] == '0' ? a[i] : 0);
        else pr1[i] = (i ? pr1[i - 1] : 0) + (s[i] == '1' ? a[i] : 0);
        if (!z2) pr2[i] = (i ? pr2[i - 1] : 0) + (s[i] == '0' ? a[i] : 0);
        else pr2[i] = (i ? pr2[i - 1] : 0) + (s[i] == '1' ? a[i] : 0);
        z1 = !z1, z2 = !z2;
    }
    int ans = LLONG_MAX;
    for (int i = 0; i + 1 < n; ++i) {
        int cost = 0;
        if (s[i] == s[i + 1]) {
            int pre, suf;
            if (s[i] == '0') {
                if (i&1) {
                    pre = i ? pr2[i - 1] : 0;
                    suf = pr1[n - 1] - pr1[i + 1];
                } else {
                    pre = i ? pr1[i - 1] : 0;
                    suf = pr2[n - 1] - pr2[i + 1];
                }
            } else {
                if (i&1) {
                    pre = i ? pr1[i - 1] : 0;
                    suf = pr2[n - 1] - pr2[i + 1];
                } else {
                    pre = i ? pr2[i - 1] : 0;
                    suf = pr1[n - 1] - pr1[i + 1];
                }
            }
            cost += pre + suf;
        } else {
            int cost1 = 0, cost2 = 0;
            cost1 += a[i]; 
            int pre, suf;
            if (s[i] == '1') {
                if (i&1) {
                    pre = i ? pr2[i - 1] : 0;
                    suf = pr1[n - 1] - pr1[i + 1];
                } else {
                    pre = i ? pr1[i - 1] : 0;
                    suf = pr2[n - 1] - pr2[i + 1];
                }
            } else {
                if (i&1) {
                    pre = i ? pr1[i - 1] : 0;
                    suf = pr2[n - 1] - pr2[i + 1];
                } else {
                    pre = i ? pr2[i - 1] : 0;
                    suf = pr1[n - 1] - pr1[i + 1];
                }
            }
            cost1 += pre + suf;
            cost2 += a[i + 1];
            if (s[i + 1] == '1') {
                if (i&1) {
                    pre = i ? pr2[i - 1] : 0;
                    suf = pr1[n - 1] - pr1[i + 1];
                } else {
                    pre = i ? pr1[i - 1] : 0;
                    suf = pr2[n - 1] - pr2[i + 1];
                }
            } else {
                if (i&1) {
                    pre = i ? pr1[i - 1] : 0;
                    suf = pr2[n - 1] - pr2[i + 1];
                } else {
                    pre = i ? pr2[i - 1] : 0;
                    suf = pr1[n - 1] - pr1[i + 1];
                }
            }
            cost2 += pre + suf;
            cost = min(cost1, cost2);
        }
        ans = min(ans, cost);
    }
    cout << ans;
}

signed main() {
    ios_base::sync_with_stdio(0); 
    cin.tie(0); cout.tie(0);

    int t = 1;
    if (MULTI_TEST) cin >> t;
    while (t--) solve();

    return 0;
}