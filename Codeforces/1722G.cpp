// https://codeforces.com/contest/1722/problem/G
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
int n;

void solve() {
    cin >> n;
    vector<int> ans;
    if (n % 4 == 2) {
        int val = (n / 4 - 1) * 4;
        for (int i = 4, j = 5, cnt = 0; cnt < val; i += 2, j += 2, cnt+=4) {
            ans.push_back(4 * i);
            ans.push_back(4 * j);
            ans.push_back(4 * i + 1);
            ans.push_back(4 * j + 1);
        }
        ans.push_back(4);
        ans.push_back(1);
        ans.push_back(2);
        ans.push_back(12);
        ans.push_back(3);
        ans.push_back(8);
    } else {
        for (int i = 1; i <= n / 4; ++i) {
            ans.push_back(4 * i);
            ans.push_back(4 * i + 1);
            ans.push_back(4 * i + 2);
            ans.push_back(4 * i + 3);
        }
        int cur = ans.size();
        int diff = n - cur;
        if (diff == 1) ans.push_back(0);
        else if (diff == 3) {
            ans.push_back(1);
            ans.push_back(3);
            ans.push_back(2);
        }
    }
    for (int i : ans) cout << i << " ";
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