// https://codeforces.com/contest/2004/problem/E
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
const int maxn = 1e7 + 5, inf = 1e18;
int n;

vector<int> s(maxn);
vector<int> primes;

void sieve() {
    s[1] = 1;
    for (int i = 2; i < maxn; i++) {
        if (!s[i]) {
            s[i] = i;
            primes.push_back(i);
            for (int j = i * i; j < maxn; j += i)
                if (!s[j]) s[j] = i;
        }
    }
}

void init() {
    for (int i = 0; i < maxn; ++i) {
        if (i&1)
            s[i] = lower_bound(primes.begin(), primes.end(), s[i]) - primes.begin() + 1;
        else 
            s[i] = 0;
    }
}

void solve() {
    cin >> n;
    int x = 0;
    for (int i = 0; i < n; ++i) {
        int a; cin >> a;
        x ^= s[a];
    }
    cout << (x ? "Alice\n" : "Bob\n");
}

signed main() {
    ios_base::sync_with_stdio(0); 
    cin.tie(0); cout.tie(0);

    sieve();
    init();
    int t = 1;
    if (MULTI_TEST) cin >> t;
    while (t--) solve();

    return 0;
}
