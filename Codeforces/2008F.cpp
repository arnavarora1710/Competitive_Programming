// https://codeforces.com/contest/2008/problem/F
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

template<class T> using oset = tree<T, null_type, less<T>, rb_tree_tag,tree_order_statistics_node_update>;
template<class T> using omset = tree<T, null_type, less_equal<T>, rb_tree_tag,tree_order_statistics_node_update>;

#define int long long
#define f first
#define s second
#define MULTI_TEST (1)

typedef pair<int, int> pi;
typedef vector<int> vi;
typedef vector<vector<int>> vii;

const int N = 200005, INF = 1e18, MOD = 1e9 + 7;
int n, k, q, x, y, u, v, a[N];

int power(int a, int b) {
    int res = 1;
    while (b) {
        if (b&1) res = (res * a) % MOD;
        a = (a * a) % MOD;
        b >>= 1;
    }
    return res;
}

int inv(int x) {
    return power(x, MOD - 2);
}

void solve() {
    cin >> n;
    for (int i = 0; i < n; ++i) cin >> a[i];
    vi s(n);
    for (int i = n - 1; i >= 0; --i)
        s[i] = ((i + 1 < n ? s[i + 1] : 0) + a[i]) % MOD;
    int num = 0, den = ((n * (n - 1)) / 2) % MOD;
    for (int i = 0; i < n; ++i) 
        num = (num + ((i + 1 < n ? s[i + 1] : 0) * a[i]) % MOD) % MOD;
    cout << (num * inv(den)) % MOD << '\n';
}

signed main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int Q = 1; if (MULTI_TEST) cin >> Q;
    while (Q--) solve();
}