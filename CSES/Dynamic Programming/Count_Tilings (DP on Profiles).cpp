#include <bits/stdc++.h>
using namespace std;
const int MOD = 1e9 + 7;
int n, m; 

bool comp(int p, int q) {
    if (p&q) return false;
    int x = (~p & ~q) & ((1 << n) - 1);  
    if (x % 3) return false;
    int y = x / 3;
    if (y & (y << 1)) return false;
    return true;
}

int main() {
    cin >> n >> m;
    vector<vector<int>> compatible(1 << n);
    for (int j = 0; j < (1 << n); ++j) {
        for (int k = 0; k < (1 << n); ++k) {
            if (comp(j, k)) compatible[j].push_back(k);
        }
    }
    vector<vector<int>> dp(m + 1, vector<int>(1 << n)); dp[0][0] = 1;
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < (1 << n); ++j) {
            for (int k : compatible[j]) {
                dp[i + 1][k] = (dp[i + 1][k] + dp[i][j]) % MOD;
            }
        }
    }
    cout << dp[m][0];
    return 0;
}