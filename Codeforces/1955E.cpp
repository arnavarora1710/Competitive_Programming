#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int max_k(string s) {
    int n = s.size();
    vector<int> dp(n + 1, 0);
    
    for (int i = 1; i <= n; ++i) {
        dp[i] = dp[i - 1];
        for (int j = 1; j <= i; ++j) {
            int ones = count(s.begin() + i - j, s.begin() + i, '1');
            int zeros = j - ones;
            if (zeros <= ones) {
                dp[i] = max(dp[i], dp[i - j] + j);
            }
        }
    }
    
    return dp[n];
}

int main() {
    int t;
    cin >> t;
    
    while (t--) {
        int n;
        cin >> n;
        string s;
        cin >> s;
        
        cout << max_k(s) << endl;
    }
    
    return 0;
}
