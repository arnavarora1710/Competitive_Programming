#include <bits/stdc++.h>
using namespace std;
int a[101];
// dp(i, j): can build a sum of j using first i coins
bool dp[101][100001];

int main() {
    int n; cin >> n; for (int i = 0; i < n; ++i) cin >> a[i];
    
    dp[0][0] = true;

    for (int i = 1; i <= n; ++i) {
        for (int j = 0; j <= 100000; ++j) {
            dp[i][j] = dp[i - 1][j];
            if (j - a[i - 1] >= 0) dp[i][j] |= dp[i - 1][j - a[i - 1]];
        }
    }

    vector<int> res;
    for (int i = 1; i <= 100000; ++i) 
        if (dp[n][i]) res.push_back(i);
    
    cout << res.size() << endl;
    for (auto& v : res) cout << v << " ";

    return 0;
}