// https://codeforces.com/problemset/problem/1538/D
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")

#include <bits/stdc++.h>
using namespace std;

#define int long long

typedef pair<int, int> pi;
#define f first
#define s second
#define MULTI_TEST (1)
const int maxn = 2e5 + 5, inf = 1e18;
int a, b, k;
vector<bool> is_prime(1e5 + 1, true);

void sieve() {
    int n = is_prime.size();
    is_prime[0] = is_prime[1] = false;
    for (int i = 2; i <= n; i++) {
        if (is_prime[i] && i * i <= n)
            for (int j = i * i; j <= n; j += i)
                is_prime[j] = false;
    }
}

int getSum(int n) {
    int nn = n, ans = 0;
    for (int i = 1; i * i <= n; ++i) {
        if (is_prime[i]) {
            while (nn % i == 0) {
                ans++, nn /= i;
            }
        }
    }
    if (nn > 1) ans++;
    return ans;
}

void solve() {
    cin >> a >> b >> k;
    if (a > b) swap(a, b);
    int ans_a = getSum(a), ans_b = getSum(b);
    int g = gcd(a, b);
    int x = g / a, y = g / b;
    int mn = (x == 1 || y == 1) ? 1 : 2;
    if (x == 1 && y == 1) mn = 2;
    int mx = ans_a + ans_b;
    if (k >= mn && k <= mx) cout << "YES\n";
    else cout << "NO\n";
}

signed main () {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    sieve();
    int t = 1;
    if (MULTI_TEST) cin >> t;
    while (t--) solve();

    return 0;
}
