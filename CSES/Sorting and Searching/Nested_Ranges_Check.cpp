#pragma GCC optimize("Ofast")
#pragma GCC optimization("unroll-loops")

#include <bits/stdc++.h>
using namespace std;

#define int long long
typedef pair<int, int> pi;
#define f first
#define s second
#define mp make_pair
#define MULTI_TEST (0)
const int maxn = 2e5 + 5, inf = 1e18;

bool cmp1(vector<int>& x, vector<int>& y) {
    if (x[0] == y[0]) return x[1] > y[1];
    else return x[0] < y[0];
}

bool cmp2(vector<int>& x, vector<int>& y) {
    if (x[0] == y[0]) return x[1] < y[1];
    else return x[0] > y[0];
}

void solve() {
    int n; cin >> n;
    vector<vector<int>> a(n, vector<int>(3));
    for (int i = 0; i < n; ++i) {
        cin >> a[i][0] >> a[i][1];
        a[i][2] = i;
    }
    vector<int> A(n), B(n);
    sort(a.begin(), a.end(), cmp1);
    int mx = -inf;
    for (int i = 0; i < n; ++i) {
        if (mx >= a[i][1]) B[a[i][2]] = 1;
        else mx = a[i][1];
    }
    sort(a.begin(), a.end(), cmp2);
    int mn = inf;
    for (int i = 0; i < n; ++i) {
        if (mn <= a[i][1]) A[a[i][2]] = 1;
        else mn = a[i][1];
    }
    for (auto& x : A) cout << x << ' ';
    cout << '\n';
    for (auto& x : B) cout << x << ' ';
}

signed main() {
    ios_base::sync_with_stdio(0); 
    cin.tie(0); cout.tie(0);

    int t = 1;
    if (MULTI_TEST) cin >> t;
    while (t--) solve();

    return 0;
}
