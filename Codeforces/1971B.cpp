// https://codeforces.com/contest/1971/problem/B
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
int n, a[maxn];

void solve() {
    map<char, int> ind;
    string s; cin >> s;
    for (int i = 0; i < s.size(); ++i) ind[s[i]] = i;
    if (ind.size() == 1) cout << "NO\n";
    else { 
        int x = (*(ind.begin())).s, y = (*(ind.rbegin())).s;
        cout << "YES\n"; swap(s[x], s[y]);
        cout << s << endl;
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