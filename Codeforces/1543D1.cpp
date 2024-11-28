// https://codeforces.com/contest/1543/problem/D1
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
int n, k;

int ask(int x) {
    cout << x << endl;
    int ret; cin >> ret;
    return ret;
}

void solve() {
    cin >> n >> k;
    int cur = 0;
    for (int i = 0; i < n; ++i) {
        int ret = ask(i ^ cur);
        if (ret == 1) return;
        cur = i;
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
