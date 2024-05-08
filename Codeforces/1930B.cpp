#pragma GCC optimize("Ofast")
#pragma GCC optimization("unroll-loops")

#include <bits/stdc++.h>
using namespace std;

#define int long long
#define MULTI_TEST (1)
int n;

void solve() {
    cin >> n;
    vector<int> a(n);
    int num = 1;
    for (int i = 0; i < n; i+=2) {
        a[i] = num; num++;
    }
    for (int i = 1; i < n; i += 2) {
        a[i] = num; num++;
    }
    for (int i = 0; i < n; ++i) cout << a[i] << " ";
    cout << endl;
}

signed main() {
    ios_base::sync_with_stdio(0); 
    cin.tie(0); cout.tie(0);

    int t = 1;
    if (MULTI_TEST) cin >> t;
    while (t--) solve();

    return 0;
}