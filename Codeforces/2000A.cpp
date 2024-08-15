// https://codeforces.com/contest/2000/problem/A
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

void solve() {
   string s; cin >> s;
   if (s.size() <= 2) cout << "NO\n";
   else {
        if (s[0] == '1' && s[1] == '0') {
            if (s[2] == '0' || (s[2] == '1' && s.size() == 3)) cout << "NO\n";
            else cout << "YES\n";
        } else cout << "NO\n";
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
