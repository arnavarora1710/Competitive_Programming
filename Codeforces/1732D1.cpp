// https://codeforces.com/contest/1732/problem/D1
#pragma GCC optimize("Ofast")
#pragma GCC optimization("unroll-loops")

#include <bits/stdc++.h>
using namespace std;

#define int long long
typedef pair<int, int> pi;
#define f first
#define s second
#define MULTI_TEST (0)
const int maxn = 2e5 + 5, inf = 1e18;
int q, x;
char tp;

void solve() {
    cin >> q;
    set<int> s;
    map<int, int> m;
    while (q--) {
        cin >> tp >> x;
        if (tp == '+') s.insert(x);
        else {
            if (!m[x]) m[x] = 1;
            for (int i = m[x]; i <= 1e8; ++i) {
                if (s.find(x * i) == s.end()) {
                    cout << x * i << endl;
                    m[x] = i;
                    break; 
                }
            }
        }
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