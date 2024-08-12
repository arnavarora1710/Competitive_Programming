#pragma GCC optimize("Ofast")
#pragma GCC optimization("unroll-loops")

#include <bits/stdc++.h>
using namespace std;

#define int long long
typedef pair<int, int> pi;
#define f first
#define s second
#define mp make_pair
#define MULTI_TEST (1)
const int maxn = 2e5 + 5, inf = 1e18;
int k;

vector<bool> is_prime(maxn, true);
vector<int> primes;

void sieve() {
    int n = is_prime.size();
    is_prime[0] = is_prime[1] = false;
    for (int i = 2; i <= n; i++) {
        if (is_prime[i] && i * i <= n)
            for (int j = i * i; j <= n; j += i)
                is_prime[j] = false;
    }
    for (int i = 2; i < n; ++i)
        if (is_prime[i]) 
            primes.push_back(i);
}

void solve() {
    cin >> k;
    cout << primes[--k] << '\n';
}

signed main() {
    ios_base::sync_with_stdio(0); 
    cin.tie(0); cout.tie(0);

    sieve();
    int t = 1;
    if (MULTI_TEST) cin >> t;
    while (t--) solve();

    return 0;
}
