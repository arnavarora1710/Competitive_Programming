// https://codeforces.com/contest/1562/problem/C
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
int n;
string s;

void solve() {
    cin >> n >> s;
    int index = -1;
    for (int i = 0; i < n; ++i)
        if (s[i] == '0') index = i;
    if (index == -1) cout << 1 << ' ' << n / 2 << ' ' << 2 << ' ' << n / 2 + 1 << '\n';
    else if (index >= n / 2) cout << 1 << ' ' << index + 1 << ' ' << 1 << ' ' << index << '\n';
    else cout << index + 1 << ' ' << n << ' ' << index + 2 << ' ' << n << '\n';
}

signed main() {
    ios_base::sync_with_stdio(0); 
    cin.tie(0); cout.tie(0);

    int t = 1;
    if (MULTI_TEST) cin >> t;
    while (t--) solve();

    return 0;
}
