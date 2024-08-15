// https://codeforces.com/contest/1934/problem/C
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
int n, m;

int ask(int x, int y) {
    cout << "? " << x << " " << y << endl;
    int res; cin >> res;
    return res;
}

void submit(int x, int y) {
    cout << "! " << x << " " << y << endl;
}

void solve() {
    cin >> n >> m;
    int tl = ask(1, 1);
    int L = max(1LL, tl + 2 - m);
    int e1 = ask(L, tl + 2 - L);
    int R = max(1LL, tl + 2 - n);
    int e2 = ask(tl + 2 - R, R);
    if (ask(L + e1 / 2, tl + 2 - L - e1 / 2) == 0)
        submit(L + e1 / 2, tl + 2 - L - e1 / 2);
    else
        submit(tl + 2 - R - e2 / 2, R + e2 / 2);
}

signed main() {
    ios_base::sync_with_stdio(0); 
    cin.tie(0); cout.tie(0);

    int t = 1;
    if (MULTI_TEST) cin >> t;
    while (t--) solve();

    return 0;
}
