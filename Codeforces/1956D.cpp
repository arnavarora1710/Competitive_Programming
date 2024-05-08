// https://codeforces.com/contest/1956/problem/D
#pragma GCC optimize("Ofast")
#pragma GCC optimization("unroll-loops")

#include <bits/stdc++.h>
using namespace std;

#define int long long
typedef pair<int, int> pi;
#define f first
#define s second
#define MULTI_TEST (0)
const int maxn = 20, inf = 1e18;
int n, a[maxn];

void solve() {
    cin >> n; for (int i = 0; i < n; ++i) cin >> a[i];
    vector<pi> real_ans;
    int cur_mx = 0;
    for (int i = 0; i < (1 << n); ++i) {
        vector<pi> ans;
        vector<int> A(a, a + n);
        for (int j = 0; j < n; ++j) {
            if (!(i & (1 << j))) { 
                ans.push_back({j + 1, j + 1});
                A[j] = 0;
            }
        }
        int old_sum = 0;
        for (int j = 0; j < n; ++j) old_sum += A[j];
        for (int j = 0; j < n; ++j) {
            int len = 0;
            while (j < n && A[j] == 0) ++len, ++j;
            
        }
        int res = 0;
        for (int j = 0; j < n; ++j) res += A[j];
        if (res > cur_mx && ans.size() <= 500000) {
            cur_mx = res;
            real_ans = ans;
        }
    }
    cout << cur_mx << " " << real_ans.size() << endl;
    for (auto v : real_ans) cout << v.f << " " << v.s << endl;
}

signed main() {
    ios_base::sync_with_stdio(0); 
    cin.tie(0); cout.tie(0);

    int t = 1;
    if (MULTI_TEST) cin >> t;
    while (t--) solve();

    return 0;
}