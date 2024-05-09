// https://codeforces.com/contest/1744/problem/E1
#pragma GCC optimize("Ofast")
#pragma GCC optimization("unroll-loops")

#include <bits/stdc++.h>
using namespace std;

#define int long long
typedef pair<int, int> pi;
#define f first
#define s second
#define MULTI_TEST (1)
const int maxn = 2e5 + 5, inf = 1e18;
int a, b, c, d;

void solve() {
    cin >> a >> b >> c >> d;
    int target = a * b;
    for (int i = 1; i * i <= target; ++i) {
        if (target % i == 0) {
            int mul, mul1, f1 = i, f2 = target / i;
            for (mul = 1; f1 * mul <= a; mul++) {}
            for (mul1 = 1; f2 * mul1 <= b; mul1++) {}
            if (f1 * mul <= c && f2 * mul1 <= d) {
                cout << f1 * mul << " " << f2 * mul1 << endl;
                return;
            }
            f1 = target / i, f2 = i;
            for (mul = 1; f1 * mul <= a; mul++) {}
            for (mul1 = 1; f2 * mul1 <= b; mul1++) {}
            if (f1 * mul <= c && f2 * mul1 <= d) {
                cout << f1 * mul << " " << f2 * mul1 << endl;
                return;
            }
        }
    } 
    cout << "-1 -1" << endl;
}

signed main() {
    ios_base::sync_with_stdio(0); 
    cin.tie(0); cout.tie(0);

    int t = 1;
    if (MULTI_TEST) cin >> t;
    while (t--) solve();

    return 0;
}