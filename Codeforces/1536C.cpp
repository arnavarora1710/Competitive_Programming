// https://codeforces.com/contest/1536/problem/C
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
int n; string s;

void solve() {
    cin >> n >> s;
    int d = 0, k = 0;
    map<pi, int> mp;
    for (int i = 0; i < n; i++) {
        if (s[i] == 'D') d++;
        else k++;
        int g = gcd(d, k);
        pi val = {d/g,k/g};
        cout << ++mp[val] << " ";
    }
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
