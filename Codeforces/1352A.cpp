// https://codeforces.com/contest/1352/problem/A
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
int n, a[maxn];

int power(int x, int y) {
    int res = 1;
    while (y) {
        if (y&1) res *= x;
        x *= x;
        y >>= 1;
    }
    return res;
}

void solve() {
    cin >> n;
    int i = 0;
    vector<int> ans;
    while (n) {
        if (n%10) ans.push_back((n%10) * power(10, i));
        i++;
        n /= 10;
    }
    cout << ans.size() << '\n';
    for (int i : ans) cout << i << ' ';
    cout << '\n';
}

signed main() {
    ios_base::sync_with_stdio(0); 
    cin.tie(0); cout.tie(0);

    int t = 1;
    if (MULTI_TEST) cin >> t;
    while (t--) solve();

    return 0;
}
