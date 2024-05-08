// https://codeforces.com/contest/1955/problem/F
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
int a, b, c, d;
map<vector<int>, int> vis;
// n <= 800

int rec(vector<int> nums) {
    if (vis[nums]) return vis[nums];
    bool some = 0;
    for (int i = 0; i < 4; ++i) {
        if (nums[i]) {
            some = 1;
            break;
        }
    }
    if (!some) return vis[nums] = 0;
    int xorr = 0;
    for (int i = 0; i < 4; ++i) {
        xorr ^= (nums[i]&1 ? i + 1 : 0);
    }
    bool win = (xorr == 0);
    int mx = 0;
    for (int i = 0; i < 4; ++i) {
        if (nums[i]) {
            nums[i]--;
            mx = max(mx, rec(nums));
            nums[i]++;
        }
    }
    return vis[nums] = mx + win;
}

void solve() {
    cin >> a >> b >> c >> d;

    vis.clear();
    int also = (a/2 + 1) * (b/2+1) * (c/2+1) * (d/2+1) - 1;
    cout << even << " " << also << endl;
    // cout << rec({a, b, c, d}) << endl;
}

signed main() {
    ios_base::sync_with_stdio(0); 
    cin.tie(0); cout.tie(0);

    int t = 1;
    if (MULTI_TEST) cin >> t;
    while (t--) solve();

    return 0;
}