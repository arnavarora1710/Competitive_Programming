// https://codeforces.com/contest/1992/problem/E
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
int n;

void solve() {
    cin >> n;
    if (n == 1) {
        cout << 9999 << '\n';
        for (int i = 2; i <= 10000; ++i)
            cout << i << ' ' << i - 1 << '\n';
        return;
    }
    int dig = 0, nn = n;
    while (nn) dig++, nn /= 10;
    string t = to_string(n);
    vector<pi> ans;
    for (int len = dig; len <= 6; ++len) {
        string s;
        while (s.size() <= len) s += t;
        while (s.size() != len) s.pop_back();
        int cal = stoll(s);
        // len = dig * a - b
        // cal = n * a - b
        // len - cal = (dig - n) * a
        // a = (len - cal) / (dig - n) 
        // len, dig, cal, n are constants
        int s1 = len - cal, s2 = dig - n;
        if (s1 % s2 == 0) {
            int a = s1 / s2;
            int b = n * a - cal;
            if (a && b && a <= 1e4 && b <= 1e4)
                ans.push_back({a, b});
        }
    }
    cout << ans.size() << '\n';
    for (auto v : ans) cout << v.f << ' ' << v.s << '\n';
}

signed main() {
    ios_base::sync_with_stdio(0); 
    cin.tie(0); cout.tie(0);

    int t = 1;
    if (MULTI_TEST) cin >> t;
    while (t--) solve();
    return 0;
}
