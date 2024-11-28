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
int n, k;
string s;

void solve() {
    cin >> n >> k >> s;
    vector<pi> cnt;
    for (int i = 0; i < n; ++i) {
        int j = i + 1, tot = 1;
        while (j < n && s[i] == s[j]) j++, tot++;
        cnt.push_back({tot, i});
        i = j - 1;
    }
    if (cnt.size() == 1) {
        cout << (n == k ? 1 : -1) << '\n';
        return;
    }
    int b = cnt.back().f;
    char c = s[cnt.back().s];
    bool ok = 1;
    int ans = n;
    if (b > k) ans = -1;
    else if (b == k) {
        for (int i = 0; i + 1 < cnt.size(); ++i) {
            if (cnt[i].f != k) {
                if (!ok) {
                    cout << -1 << '\n';
                    return;
                } else {
                    if (cnt[i].f == 2 * k) {
                        if (s[cnt[i].s] == c) {
                            cout << -1 << '\n';
                            return;
                        } else {
                            ans = cnt[i].s + k;
                        }
                    } else {
                        cout << -1 << '\n';
                        return;
                    }
                }
                ok = 0;
            }
        }
    } else {
        for (int i = 0; i + 1 < cnt.size(); ++i) {
            if (cnt[i].f != k) {
                if (!ok) {
                    cout << -1 << '\n';
                    return;
                } else {
                    if (cnt[i].f == 2 * k - b || cnt[i].f == k - b) {
                        if (s[cnt[i].s] != c) {
                            cout << -1 << '\n';
                            return;
                        } else {
                            ans = cnt[i].s + k - b;
                        }
                    } else {
                        cout << -1 << '\n';
                        return;
                    }
                    ok = 0;
                }
            }
        }
    }
    cout << ans << '\n';
}

signed main() {
    ios_base::sync_with_stdio(0); 
    cin.tie(0); cout.tie(0);

    int t = 1;
    if (MULTI_TEST) cin >> t;
    while (t--) solve();

    return 0;
}
