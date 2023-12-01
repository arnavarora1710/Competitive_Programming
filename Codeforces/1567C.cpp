// https://codeforces.com/problemset/problem/1567/C
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int t, zero; ll dp[10][2]; string n;

int countWaysToBuild(int num) {
    int ways = 0; zero = 0;
    for (int addend = 0; addend <= 9; ++addend) {
        if (num - addend <= 9 && num - addend >= 0) {
            if (addend == 0) zero++;
            if (num - addend == 0) zero++;
            ways++;
        }
    }
    return ways;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0); 
    cin >> t;
    while (t--) {
        cin >> n; reverse(n.begin(), n.end());
        dp[0][0] = countWaysToBuild(n[0] - '0'); 
        int deduct = zero;
        dp[0][1] = countWaysToBuild(n[0] - '0' + 10);
        if (n.size() <= 1) {
            cout << dp[0][0] - deduct << endl; continue;
        }
        dp[1][0] = countWaysToBuild(n[1] - '0'); dp[1][1] = countWaysToBuild(n[1] - '0' + 10);
        for (int i = 2; i < n.size(); ++i) {
            int num = n[i] - '0';
            dp[i][0] = dp[i - 2][0] * countWaysToBuild(num) + dp[i - 2][1] * countWaysToBuild(num - 1);
            deduct = zero;
            dp[i][1] = dp[i - 2][0] * countWaysToBuild(num + 10) + dp[i - 2][1] * countWaysToBuild(num + 9);
        }
        cout << dp[n.size() - 1][0] * dp[n.size() - 2][0] - deduct << endl;
    }
    return 0;
}