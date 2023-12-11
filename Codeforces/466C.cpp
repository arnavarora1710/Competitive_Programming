// https://codeforces.com/problemset/problem/466/C
#include <bits/stdc++.h>
using namespace std;
const int MAXN = 500005;
int n, a[MAXN]; long long ans, sum, sum1, ct;

int main() {
    cin >> n; for (int i = 0; i < n; ++i) cin >> a[i], sum += a[i];
    if (sum % 3) cout << 0;
    else {
        sum /= 3;
        for (int i = 0; i < n - 1; ++i) {
            sum1 += a[i];
            if (sum1 == 2 * sum) ans += ct;
            if (sum1 == sum) ct++;
        }
        cout << ans;
    }
    return 0;
}
// For proof, refer to https://codeforces.com/blog/entry/13758?#comment-187357