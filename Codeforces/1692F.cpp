// https://codeforces.com/problemset/problem/1692/F
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
int n, x;
vector<vector<int>> pr;

void solve() {
    cin >> n; map<int, int> cnt;
    for (int i = 0; i < n; ++i) {
        cin >> x;
        cnt[x%10]++;
    }
    for (auto& v : pr) {
        bool ok1 = 0, ok2 = 0, ok3 = 0;
        if (cnt[v[0]]) {
            ok1 = 1;
            cnt[v[0]]--;
        }
        if (cnt[v[1]]) {
            ok2 = 1;
            cnt[v[1]]--;
        }
        if (cnt[v[2]]) {
            ok3 = 1;
            cnt[v[2]]--;
        }
        if (ok1 && ok2 && ok3) {
            cout << "YES\n";
            return;
        }
        if (ok1) cnt[v[0]]++;
        if (ok2) cnt[v[1]]++;
        if (ok3) cnt[v[2]]++;
    }
    cout << "NO\n";
}

signed main() {
    ios_base::sync_with_stdio(0); 
    cin.tie(0); cout.tie(0);

    for (int i = 0; i <= 9; ++i) {
        for (int j = 0; j <= 9; ++j) {
            for (int k = 0; k <= 9; ++k) {
                int val = i + j + k;
                val %= 10;
                if (val == 3) {
                    pr.push_back({i, j, k});
                }
            }
        }
    }

    int t = 1;
    if (MULTI_TEST) cin >> t;
    while (t--) solve();

    return 0;
}