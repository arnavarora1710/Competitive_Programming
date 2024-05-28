// https://codeforces.com/contest/1975/problem/A
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

void solve() {
    cin >> n; for (int i = 0; i < n; ++i) cin >> a[i];
    vector<int> b(a, a + n);
    vector<int> c = b;
    sort(c.begin(), c.end());
    if (b == c) {
        cout << "Yes\n";
    } else if (a[0] < a[n - 1]) {
        cout << "No\n";
    } else {
        int i = n - 2;
        while (i >= 0 && a[i] <= a[i + 1]) i--;
        for (int j = 0; j + 1 <= i; ++j) {
            if (a[j] > a[j + 1]) {
                cout << "No\n";
                return;
            }
        } 
        cout << "Yes\n";
    }
}

signed main() {
    ios_base::sync_with_stdio(0); 
    cin.tie(0); cout.tie(0);

    int t = 1;
    if (MULTI_TEST) cin >> t;
    while (t--) solve();

    return 0;
}
