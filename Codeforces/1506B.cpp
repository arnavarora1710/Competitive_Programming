// https://codeforces.com/contest/1506/problem/B
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
int n, k;
string s;

void solve() {
    cin >> n >> k >> s;
    int first = -1, last = -1, cnt = 0;
    for (int i = 0; i < n; ++i) {
        if (s[i] == '*') {
            if (first == -1) first = i;
            last = i;
            cnt++;
        }
    }
    if (first == last) cout << 1 << endl;
    else if (last - first <= k) cout << 2 << endl;
    else { 
        int ans = 2;
        for (int i = first; i + k < last; ++i) {
            int last1 = -1;
            for (int j = i; j <= i + k; ++j) {
                if (s[j] == '*') {
                    last1 = j;
                }
            }
            i = last1 - 1;
            ans++;
        }
        cout << ans << endl;
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