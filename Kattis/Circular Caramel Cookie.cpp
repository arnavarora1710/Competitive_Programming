#include <bits/stdc++.h>
using namespace std;

long check(long double m) {
    long ans = 0;
    for (int i = floor(m) + 1; i >= 1; --i) ans += floor(sqrtl(m * m - i * i));
    return 4 * ans;
}

int main() {
    int s; cin >> s;

    long double l = -1, r = 17842;
    while (r - l > 1e-7) {
        long double m = l + (r - l) / 2;
        if (check(m) <= s) l = m;
        else r = m;
    }

    cout << setprecision(18) << l << endl;

    return 0;
}