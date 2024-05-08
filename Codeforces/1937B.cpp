// https://codeforces.com/contest/1937/problem/D
#pragma GCC optimize("Ofast")
#pragma GCC optimization("unroll-loops")

#include <bits/stdc++.h>
using namespace std;

#define int long long
#define MULTI_TEST (1)
int n, a[2][200005];
char ch;

void solve() {
    cin >> n;
    for (int i = 0; i < 2; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> ch;
            a[i][j] = ch - '0';
        }
    }
    int idx, cnt = 0;
    for (int i = 0; i < n; ++i) {
        int tmp = i;
        while (i + 1 < n && a[1][i] == a[0][i + 1]) i++;
        if (i == n - 1) {
            cnt += i - tmp + 1;
            idx = i;
        } else {
            if (a[1][i] < a[0][i + 1]) {
                cnt += i - tmp + 1;
                idx = tmp;
                break;
            }
        }
    }
    string ans;
    for (int i = 0; i <= idx; ++i) {
        ans.push_back(a[0][i] + '0');
    }
    for (int i = idx; i < n; ++i) {
        ans.push_back(a[1][i] + '0');
    }
    cout << ans << endl << cnt << endl;
}

signed main() {
    ios_base::sync_with_stdio(0); 
    cin.tie(0); cout.tie(0);

    int t = 1;
    if (MULTI_TEST) cin >> t;
    while (t--) solve();

    return 0;
}