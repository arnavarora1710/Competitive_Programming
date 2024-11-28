// https://codeforces.com/contest/877/problem/A
#pragma GCC optimize("Ofast")
#pragma GCC optimization("unroll-loops")

#include <bits/stdc++.h>
using namespace std;

#define int long long
typedef pair<int, int> pi;
#define f first
#define s second
#define mp make_pair
#define MULTI_TEST (0)
const int maxn = 2e5 + 5, inf = 1e18;
string s;

void solve() {
    cin >> s;
    int n = s.size();
    map<string, int> cnt;
    for (int k = 2; k < 6; ++k) {
        for (int i = 0; i + k < n; ++i) {
            string t;
            for (int j = i; j <= i + k; ++j) t += s[j];
            cnt[t]++;
        }
    }
    vector<string> friends = {"Danil", "Olya", "Slava", "Ann", "Nikita"};
    for (int i = 0; i < 5; ++i) {
        if (cnt[friends[i]] == 1) {
            bool ok = 1;
            for (int j = 0; j < 5; ++j) {
                if (i != j) {
                    if (cnt[friends[j]] != 0) {
                        ok = 0;
                    }
                }
            }
            if (ok) {
                cout << "YES\n";
                return;
            }
        }
    }
    cout << "NO\n";
}

signed main() {
    ios_base::sync_with_stdio(0); 
    cin.tie(0); cout.tie(0);

    int t = 1;
    if (MULTI_TEST) cin >> t;
    while (t--) solve();

    return 0;
}
