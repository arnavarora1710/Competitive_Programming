// https://codeforces.com/contest/1984/problem/B
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
int n, a[maxn];
string s;

int cntDig(int x) {
    int ans = 0;
    while (x) {
        ans++;
        x /= 10;
    }
    return ans;
}

void solve() {
    cin >> s;
    bool ok = 1;
    for (int i = 0; i + 1 < s.size(); ++i) {
        if (s[i] == '0') ok = 0;
    }
    if (s[0] == '1' && s.back() != '9' && ok) cout << "YES\n";
    else cout << "NO\n";
}

signed main() {
    ios_base::sync_with_stdio(0); 
    cin.tie(0); cout.tie(0);

    int t = 1;
    if (MULTI_TEST) cin >> t;
    while (t--) solve();

    return 0;
}
