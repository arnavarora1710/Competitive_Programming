#include <bits/stdc++.h>
using namespace std;

int main() {
    int n; cin >> n;
    vector<int> a(n); for (int& x : a) cin >> x;
    int mn = 1e9;
    for (int i = 0; i < (1 << n); ++i) {
        int sum1 = 0, sum2 = 0;
        for (int j = 0; j < n; ++j) {
            if ((i >> j)&1) sum1 += a[j];
            else sum2 += a[j];
        }
        mn = min(mn, abs(sum1 - sum2));
    }
    cout << mn << '\n';
    return 0;
}
