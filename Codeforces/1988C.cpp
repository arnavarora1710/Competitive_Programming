// https://codeforces.com/contest/1988/problem/C
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
int n;

void solve() {
    cin >> n;
    vector<int> ans;
    ans.push_back(n);
    for (int i = 0; i < 64; ++i) {
        if ((n >> i)&1) {
            int num = n ^ (1LL << i);
            if (num) ans.push_back(num);
        }
    }
    reverse(ans.begin(), ans.end());
    cout << ans.size() << '\n';
    for (auto v : ans) cout << v << ' ';
    cout << '\n'; 
}

signed main() {
    ios_base::sync_with_stdio(0); 
    cin.tie(0); cout.tie(0);

    int t = 1;
    if (MULTI_TEST) cin >> t;
    while (t--) solve();

    return 0;
}
