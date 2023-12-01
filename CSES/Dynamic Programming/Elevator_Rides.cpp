#include <bits/stdc++.h>
using namespace std;
const int MAXN = 20;
int n, x, a[MAXN]; pair<int, int> dp[1 << MAXN];
// dp - {total weight till now, min rides}

int main() {
    cin >> n >> x; for (int i = 0; i < n; ++i) cin >> a[i];
    dp[0] = {0, 1};
    for (int i = 1; i < (1 << n); ++i) {
        int minWeight = INT_MAX, minRides = INT_MAX;
        for (int j = 0; j < n; ++j) {
            if ((i>>j)&1) {
                int weight = dp[i ^ (1 << j)].first, rides = dp[i ^ (1 << j)].second;
                if (weight + a[j] <= x) {
                    if (minRides >= rides && minWeight > weight + a[j]) {
                        minWeight = weight + a[j]; minRides = rides;
                    }
                } else {
                    if (minRides >= rides + 1 && minWeight > a[j]) {
                        minWeight = a[j]; minRides = rides + 1;
                    }
                }
            }
        }
        dp[i] = {minWeight, minRides};
    }
    cout << dp[(1 << n) - 1].second;
    return 0;
}