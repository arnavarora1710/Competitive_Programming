// https://codeforces.com/problemset/problem/102/B
#pragma GCC optimize("Ofast")
#pragma GCC optimization("unroll-loops")

#include <bits/stdc++.h>
using namespace std;

#define int long long
typedef pair<int, int> pi;
#define f first
#define s second
#define MULTI_TEST (0)
const int maxn = 2e5 + 5, inf = 1e18;
string s; 

void solve() {
    cin >> s;
    int ans = 0;
    while (s.size() != 1) {
        ans++;
        int num = 0;
        for (char c : s) num += (c - '0');
        s = to_string(num);
    }
    cout << ans << endl;
}

signed main() {
    ios_base::sync_with_stdio(0); 
    cin.tie(0); cout.tie(0);

    int t = 1;
    if (MULTI_TEST) cin >> t;
    while (t--) solve();

    return 0;
}