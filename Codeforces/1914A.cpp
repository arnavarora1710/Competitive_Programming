// https://codeforces.com/contest/1914/problem/A
#include <bits/stdc++.h>
using namespace std;
#define int long long
int t, n, f[26]; string a;

signed main() {
    cin >> t;
    while (t--) {
        cin >> n >> a; memset(f, 0, sizeof(f));
        for (int i = 0; i < a.size(); ++i) f[a[i] - 'A']++;
        int ans = 0;
        for (int i = 0; i < 26; ++i) if (f[i] >= i + 1) ans++;
        cout << ans << endl;
    }
    return 0;
}