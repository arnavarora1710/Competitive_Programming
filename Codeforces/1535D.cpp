// https://codeforces.com/problemset/problem/1535/D
#pragma GCC optimize("Ofast")
#pragma GCC optimization("unroll-loops")

#include <bits/stdc++.h>
using namespace std;

#define int long long
#define endl '\n'
#define MULTI_TEST (0)
int k, q, p; char c, ch;
vector<vector<int>> dp;
vector<string> seg;

int rec(int ext_idx, int int_idx) {
    if (!ext_idx) {
        if (seg[ext_idx][int_idx] != '?') return dp[ext_idx][int_idx] = 1;
        else return dp[ext_idx][int_idx] = 2;
    }

    int left = rec(ext_idx - 1, 2 * int_idx);
    int right = rec(ext_idx - 1, 2 * int_idx + 1);

    if (seg[ext_idx][int_idx] == '1')
        dp[ext_idx][int_idx] += right;
    else if (seg[ext_idx][int_idx] == '0')
        dp[ext_idx][int_idx] += left;
    else
        dp[ext_idx][int_idx] += left + right;

    return dp[ext_idx][int_idx];
}

void recup(int ext_idx, int int_idx) {
    if (ext_idx == k) return;

    if (ext_idx) {
        if (seg[ext_idx][int_idx] == '?')
            dp[ext_idx][int_idx] = dp[ext_idx - 1][2 * int_idx] + dp[ext_idx - 1][2 * int_idx + 1];
        else if (seg[ext_idx][int_idx] == '1')
            dp[ext_idx][int_idx] = dp[ext_idx - 1][2 * int_idx + 1];
        else
            dp[ext_idx][int_idx] = dp[ext_idx - 1][2 * int_idx];
    } else {
        if (seg[ext_idx][int_idx] == '?') dp[ext_idx][int_idx] = 2;
        else dp[ext_idx][int_idx] = 1;
    }

    recup(ext_idx + 1, int_idx / 2);
}

void solve() {
    cin >> k; seg.resize(k); dp.resize(k);

    for (int i = k - 1; i >= 0; --i) {
        dp[k - i - 1].resize(1 << i);
        seg[k - i - 1].resize(1 << i);
        for (int j = 0; j < (1 << i); ++j) {
            cin >> ch;
            seg[k - i - 1][j] = ch;
        }
    }

    rec(k - 1, 0);

    cin >> q;
    while (q--) {
        cin >> p >> c; --p;

        int sum = (1 << (k - 1)), x = 0;
        for (int i = k - 2; i >= 0; --i, ++x) {
            if (sum > p) break;
            sum += (1 << i);
        }

        int ext_idx = x;
        int m = (sum - (1 << (k - x - 1)));
        int int_idx = (m == 0 ? p : p % m);

        seg[ext_idx][int_idx] = c;
        recup(ext_idx, int_idx);
        
        cout << dp[k - 1][0] << endl;
    }
}

signed main() {
    ios_base::sync_with_stdio(0); 
    cin.tie(0); cout.tie(0);

    int t = 1;
    if (MULTI_TEST) cin >> t;
    while (t--) solve();

    return 0;
}