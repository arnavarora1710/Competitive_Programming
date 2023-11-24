#include <bits/stdc++.h>
using namespace std;
int n, a[20]; long mn = LONG_MAX;

int main() {
    cin >> n; for (int i = 0; i < n; ++i) cin >> a[i];
    for (int i = 0; i < (1 << n); ++i) {
        int num = i; long diff = 0;
        for (int j = 0; j < n; ++j) num&1 ? diff += a[j] : diff -= a[j], num >>= 1;
        mn = min(mn, abs(diff));
    }
    cout << mn; 
    return 0;
}   