// https://codeforces.com/contest/1553/problem/D
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
string s, t;

void submit(bool y) {
    cout << (y ? "YES\n" : "NO\n");
}

void solve() {
    cin >> s >> t;
    while (!t.empty()) {
        if (s.empty()) {
            submit(0);
            return;
        }
        if (s.back() == t.back()) {
            s.pop_back(); t.pop_back();
        } else {
            if (s.size() < 2) {
                submit(0);
                return;
            }
            s.pop_back(); s.pop_back();
        }
    }
    submit(1);
}

signed main() {
    ios_base::sync_with_stdio(0); 
    cin.tie(0); cout.tie(0);

    int t = 1;
    if (MULTI_TEST) cin >> t;
    while (t--) solve();

    return 0;
}