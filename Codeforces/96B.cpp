// https://codeforces.com/contest/96/problem/B
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

int construct(int len) {
    int num = stoll(s), mn = inf;
    for (int i = 0; i < (1 << len); ++i) {  
        int fours = __builtin_popcount(i);
        if (fours != len - fours) continue;
        string result;
        for (int j = 0; j < len; ++j) {
            if (i & (1 << j)) result += '4';
            else result += '7';
        }
        int ans = stoll(result);
        if (ans >= num) mn = min(mn, ans);
    }
    return (mn == inf ? -1 : mn);
}

void solve() {
    cin >> s;
    int n = s.size();
    int ans = construct(n);
    if (ans == -1) ans = construct(n + 1 + !(n&1));
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