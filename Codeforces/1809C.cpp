// https://codeforces.com/contest/1809/problem/C
#pragma GCC optimize("Ofast")
#pragma GCC optimization("unroll-loops")

#include <bits/stdc++.h>
using namespace std;

#define int long long
typedef pair<int, int> pi;
#define f first
#define s second
#define MULTI_TEST (1)
const int maxn = 2e5 + 5, inf = 1e18;
int n, k;

void solve() {
    cin >> n >> k;
    int i = 1, sum = 0;
    vector<int> ans = {-1};
    while (sum < k) {
        ans.push_back(2);
        sum += i++;
    }
    if (sum > k)
        ans.back() = 2 * (k - sum) + 1;
    for (; i <= n; ++i) 
        ans.push_back(-1000);
    for (int j = 1; j < ans.size(); ++j) cout << ans[j] << " ";
    cout << endl;
}

signed main() {
    ios_base::sync_with_stdio(0); 
    cin.tie(0); cout.tie(0);

    int t = 1;
    if (MULTI_TEST) cin >> t;
    while (t--) solve();

    return 0;
}