// https://codeforces.com/problemset/problem/1619/D
#pragma GCC optimize("Ofast")
#pragma GCC optimization("unroll-loops")

#include <bits/stdc++.h>
using namespace std;

#define int long long
typedef vector<int> vi;
typedef vector<vi> vii;
#define MULTI_TEST (1)
int n, m; vii a;

bool check(int mid) {
    set<int> s; bool two = 0;
    for (int shop = 0; shop < m; ++shop) {
        int ct = 0;
        for (int person = 0; person < n; ++person) {
            if (a[shop][person] >= mid) s.insert(person), ct++;
        }
        if (ct > 1) two = 1;
    }
    if (!two) return false;
    return s.size() == n;
}

void solve() {
    cin >> m >> n; a.resize(m);
    for (int i = 0; i < m; ++i) { 
        a[i].resize(n);
        for (int j = 0; j < n; ++j) cin >> a[i][j];
    }
    int l = 1, r = 1e13;
    while (r - l > 1) {
        int mid = l + (r - l) / 2;
        if (check(mid)) l = mid;
        else r = mid;
    }
    cout << l << endl;
}

signed main() {
    ios_base::sync_with_stdio(0); 
    cin.tie(0); cout.tie(0);

    int t = 1;
    if (MULTI_TEST) cin >> t;
    while (t--) solve();

    return 0;
}