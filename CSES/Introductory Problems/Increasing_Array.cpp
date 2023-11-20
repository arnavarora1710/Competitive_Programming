#include <bits/stdc++.h>
using namespace std;
long n, x;

int main() {
    cin >> n; long prev = 0, ans = 0;
    for (int i = 0; i < n; ++i) {
        cin >> x;
        if (prev > x) ans += prev - x;
        prev = max(prev, x);
    }
    cout << ans;
    return 0;
}