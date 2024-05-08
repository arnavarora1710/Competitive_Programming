// https://codeforces.com/contest/1966/problem/C
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
int n, aa[maxn];

void solve() {
    cin >> n; for (int i = 0; i < n; ++i) cin >> aa[i];
    set<int> s(aa, aa + n);
    vector<int> a(s.begin(), s.end());
    int done = 0, alice = inf, bob = inf;
    bool turn = 1;
    for (int i = 0; i < a.size(); ++i) {
        if (a[i] - done > 1) {
            if (turn) alice = min(alice, i);
            else bob = min(bob, i);
        }
        turn = !turn;
        done = a[i];
    }
    if ((a.size())&1) {
        if (alice > bob) cout << "Bob\n";
        else cout << "Alice\n";
    } else {
        if (alice < bob) cout << "Alice\n";
        else cout << "Bob\n";
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