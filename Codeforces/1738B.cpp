// https://codeforces.com/contest/1738/problem/B
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
int n, k;

bool check(vector<int> a) {
    vector<int> b = a;
    sort(a.begin(), a.end());
    return a == b;
}

void submit(bool yes) {
    cout << (yes ? "YES\n" : "NO\n");
}

void solve() {
    cin >> n >> k;
    vector<int> a(k);
    for (int i = 0; i < k; ++i) cin >> a[i];
    vector<int> b(k - 1);
    for (int i = 1; i < k; ++i)
        b[i - 1] = a[i] - a[i - 1];
    if (check(b)) {
        int len = n - k + 1;
        int sum = a[0];
        int last = (k > 1 ? b[0] : inf);
        submit(ceil(sum / (double) len) <= last);
    } else submit(0);
}

signed main() {
    ios_base::sync_with_stdio(0); 
    cin.tie(0); cout.tie(0);

    int t = 1;
    if (MULTI_TEST) cin >> t;
    while (t--) solve();

    return 0;
}