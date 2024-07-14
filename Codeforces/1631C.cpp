// https://codeforces.com/contest/1631/problem/C
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
int n, k;
map<int, int> zeroed;

vector<pi> make_ans(int nn, int kk) {
    vector<pi> ans;
    ans.push_back({kk, nn - 1});
    if (kk) ans.push_back({0, zeroed[kk]});
    for (int i = 1; i < nn / 2; ++i) {
        if (i != kk && i != zeroed[kk]) {
            ans.push_back({i, zeroed[i]});
        }
    }
    return ans;
}

void solve() {
    cin >> n >> k;
    zeroed.clear();
    int l = 0, r = n - 1;
    while (l < r) {
        zeroed[l] = r, zeroed[r] = l;
        l++, r--;
    }
    vector<pi> ans;
    if (k != n - 1) {
        ans = make_ans(n, k);
    } else {
        if (n == 4) {
            cout << -1 << '\n';
            return;
        }
        ans = make_ans(n, k - 1);
        int sz = ans.size();
        swap(ans[sz - 1].s, ans[sz - 2].s);
    }
    for (auto& v : ans) cout << v.f << ' ' << v.s << '\n';
}

signed main() {
    ios_base::sync_with_stdio(0); 
    cin.tie(0); cout.tie(0);

    int t = 1;
    if (MULTI_TEST) cin >> t;
    while (t--) solve();

    return 0;
}
