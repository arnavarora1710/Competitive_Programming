// https://codeforces.com/problemset/problem/1511/D
#pragma GCC optimize("Ofast")
#pragma GCC optimization("unroll-loops")

#include <bits/stdc++.h>
using namespace std;

#define int long long
typedef pair<int, int> pi;
#define f first
#define s second
#define MULTI_TEST (0)
int n, k, cnt[26];
vector<int> ord;

void dfs(int v) {
    while (cnt[v] < k) {
        int u = cnt[v]++;
        dfs(u);
        ord.push_back(u);
    }
}

void solve() {
    cin >> n >> k;
    dfs(0);
    cout << "a";
    int kk = ord.size();
    for (int i = 0; i < n - 1; ++i) 
        cout << (char) (ord[i % kk] + 'a'); 
}

signed main() {
    ios_base::sync_with_stdio(0); 
    cin.tie(0); cout.tie(0);

    int t = 1;
    if (MULTI_TEST) cin >> t;
    while (t--) solve();

    return 0;
}