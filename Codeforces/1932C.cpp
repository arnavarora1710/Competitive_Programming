// https://codeforces.com/contest/1932/problem/C
#pragma GCC optimize("Ofast")
#pragma GCC optimization("unroll-loops")

#include <bits/stdc++.h>
using namespace std;

#define int long long
#define MULTI_TEST (1)
const int maxn = 200005;
int n, m, a[maxn];
string q;

void solve() {
    cin >> n >> m;
    for (int i = 0; i < n; ++i) cin >> a[i];
    int i = 0, j = n - 1; 
    cin >> q;
    for (char qq : q) {
        if (qq == 'L') i++;
        else j--;
    }
    reverse(q.begin(), q.end());
    vector<int> ans;
    int prod = 1;
    for (char qq : q) {
        if (qq == 'L') {
            i--;
            prod = (prod * a[i]) % m;
            ans.push_back(prod);
        }
        else {
            j++;
            prod = (prod * a[j]) % m;
            ans.push_back(prod);
        }
    }
    reverse(ans.begin(), ans.end());
    for (int aa : ans) cout << aa << " ";
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