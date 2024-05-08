// https://codeforces.com/problemset/problem/1872/E
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
int n, q, tp, l, r, g, a[maxn];
string s;
// 1) assuming you init with xor for 0s and xor for 1s
// we have some answer beforehand and now every update
// we just want to remove and add stuff in
// 2) something to do with bits of a[i]?
// like store the xor for every bit?
// even bits on - 0, odd bits on - 1
// we have prefix xor so we can query xor in [l, r] in O(1)

void solve() {
    cin >> n;
    for (int i = 0; i < n; ++i) cin >> a[i];
    cin >> s >> q;
    vector<int> pr(n); pr[0] = a[0];
    for (int i = 1; i < n; ++i) pr[i] = pr[i - 1] ^ a[i];
    int one = 0, zero = 0;
    for (int i = 0; i < n; ++i) {
        if (s[i] == '0') zero ^= a[i];
        else one ^= a[i];
    }
    while (q--) {
        cin >> tp;
        if (tp == 1) {
            cin >> l >> r; --l, --r;
            int val = pr[r] ^ (l ? pr[l - 1] : 0);
            one ^= val; zero ^= val;
        } else {
            cin >> g;
            if (g) cout << one << " ";
            else cout << zero << " ";
        }
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