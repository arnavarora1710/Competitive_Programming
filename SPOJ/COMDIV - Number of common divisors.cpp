#pragma GCC optimize("Ofast")
#pragma GCC optimization("unroll-loops")

#include <bits/stdc++.h>
using namespace std;

#define int long long
typedef pair<int, int> pi;
#define f first
#define s second
#define MULTI_TEST (1)
int a, b;

void solve() {
    scanf("%lld%lld", &a, &b);
    a = __gcd(a, b);
    int cnt = 0;
    for (int j = 1; j * j <= a; ++j) {
        if (a % j == 0) {
            cnt++;
            if (j != a / j) cnt++;
        }
    }
    printf("%lld\n", cnt);
}

signed main() {
    ios_base::sync_with_stdio(0); 
    cin.tie(0); cout.tie(0);

    int t = 1;
    if (MULTI_TEST) scanf("%lld", &t);
    while (t--) solve();

    return 0;
}