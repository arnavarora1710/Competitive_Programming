// https://codeforces.com/problemset/problem/1883/G1
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
int n, trash, a[maxn], b[maxn];
// 1) test cases look informative
// 2) it feels like you don't need to shift for optimality
// i.e. if you have a bad pair just discard it?
// lets find counter : what if shifting fixes 2 pairs
// 1 4 5 
// 1 2 5
// 3) greedy : pair smallest and biggest (you can reorder)
// 4) above greedy seems incorrect
// maybe pair biggest with biggest if it works
// otherwise discard it
// 5) bsta on the numbers to discard

bool check(int m) {
    int i = 0;
    for (int j = m; j < n; ++j, ++i)
        if (a[i] >= b[j]) return false;
    return true;
}

void solve() {
    cin >> n >> trash; a[0] = 1;
    for (int i = 1; i < n; ++i) cin >> a[i];
    for (int i = 0; i < n; ++i) cin >> b[i];
    sort(a, a + n); sort(b, b + n);
    int l = -1, r = n;
    while (r - l > 1) {
        int m = l + (r - l) / 2;
        if (!check(m)) l = m;
        else r = m;
    }
    cout << r << endl;
}

signed main() {
    ios_base::sync_with_stdio(0); 
    cin.tie(0); cout.tie(0);

    int t = 1;
    if (MULTI_TEST) cin >> t;
    while (t--) solve();

    return 0;
}