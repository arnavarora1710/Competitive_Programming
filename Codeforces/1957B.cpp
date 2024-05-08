// https://codeforces.com/contest/1957/problem/B
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
    vector<int> ans;
    int val = (1 << (int) log2(k)) - 1;
    ans.push_back(val);
    if (n == 1) cout << k << endl;
    else {
        ans.push_back((k - val));
        while (ans.size() != n) ans.push_back(0);
        for (int i : ans) cout << i << " ";
        cout << endl;
    }
    // int cnt = 0;
    // for (int i = 30; i >= 0; --i) {
    //     if (ans.size() < n && k - (1 << i) >= 0) {
    //         cerr << (1 << i) << endl;
    //         ans.push_back(1 << i);
    //         k -= (1 << i);
    //     }
    // }

    // while (k) {
    //     if (ans.size() < n && k&1) ans.push_back(1 << cnt);
    //     k >>= 1;
    //     cnt++;
    // }
    // while (ans.size() != n) ans.push_back(0);
}

signed main() {
    ios_base::sync_with_stdio(0); 
    cin.tie(0); cout.tie(0);

    int t = 1;
    if (MULTI_TEST) cin >> t;
    while (t--) solve();

    return 0;
}