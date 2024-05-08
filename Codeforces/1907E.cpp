// https://codeforces.com/problemset/problem/1907/E
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
int n;

int calc(int nn) { return ((nn + 1) * (nn + 2)) / 2; }

int rec(int nn) {
    if (nn % 10 == nn) return calc(nn);
    return calc(nn % 10) * rec(nn / 10);
}

void solve() {
    cin >> n;
    cout << rec(n) << endl;
}

signed main() {
    ios_base::sync_with_stdio(0); 
    cin.tie(0); cout.tie(0);

    int t = 1;
    if (MULTI_TEST) cin >> t;
    while (t--) solve();

    return 0;
}