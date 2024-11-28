// https://codeforces.com/contest/1986/problem/E
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

void solve() {
    cin >> n >> k;
    for (int i = 0; i < n; ++i) cin >> a[i];
    map<int, vector<int>> m;
    for (int i = 0; i < n; ++i) m[a[i] % k].push_back(i);
    int ans = 0, cnt = 0;
    for (auto& v : m) {
        if (v.s.size() % 2 != 0) {
            if (cnt == 1 || n % 2 == 0) {
                cout << -1 << '\n';
                return;
            }
            else if (n&1) cnt++;
        }
        vector<int> res;
        for (auto x : v.s) res.push_back(a[x] / k);
        sort(res.begin(), res.end());
        if (res.size() % 2 == 0) {
            for (int i = 0; i < res.size(); i += 2) {
                ans += res[i + 1] - res[i];
            }
        } else {
            vector<int> odd(res.size()), even(res.size());
            for (int i = 0; i + 1 < res.size(); i += 2) {
                even[i] = (res[i + 1] - res[i]);
            }
            for (int i = 1; i + 1 < res.size(); i += 2) {
                odd[i] = (res[i + 1] - res[i]);
            }
            vector<int> oddpr(res.size()), oddsuff(res.size()), evenpr(res.size()), evensuff(res.size());
            for (int i = 0; i < res.size(); ++i) {
                oddpr[i] = (i ? oddpr[i - 1] : 0) + odd[i];
                evenpr[i] = (i ? evenpr[i - 1] : 0) + even[i];    
            }
            for (int i = res.size() - 1; i >= 0; --i) {
                oddsuff[i] = (i + 1 < res.size() ? oddsuff[i + 1] : 0) + odd[i];
                evensuff[i] = (i + 1 < res.size() ? evensuff[i + 1] : 0) + even[i];
            }
            int mn = inf;                
            for (int i = 0; i < res.size(); ++i) {
                int cost; 
                if (i&1) {
                    cost = even[i - 1] + odd[i] + (i >= 2 ? evenpr[i - 2] : 0) + (i + 2 < res.size() ? oddsuff[i + 2] : 0);
                } else {
                    cost = (i ? evenpr[i - 1] : 0) + (i + 1 < res.size() ? oddsuff[i + 1] : 0);
                }
                mn = min(mn, cost);
            }
            ans += mn;
        }
    }
    cout << ans << '\n';
}

signed main() {
    ios_base::sync_with_stdio(0); 
    cin.tie(0); cout.tie(0);

    int t = 1;
    if (MULTI_TEST) cin >> t;
    while (t--) solve();

    return 0;
}
