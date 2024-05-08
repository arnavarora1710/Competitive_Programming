#pragma GCC optimize("Ofast")
#pragma GCC optimization("unroll-loops")

#include <bits/stdc++.h>
using namespace std;

#define int long long
typedef pair<int, int> pi;
#define f first
#define s second
#define MULTI_TEST (0)
int n;
int pr[26][100005]; 
string s, t;
// find the smallest f string that satisfies a k string?
// build it? and check if its <= N
// set<char> ok;
// abcaaabcaaabcaaabcaaabcaa
// ab, k = 4 => aaaabbbb
// abcabcabcabc

bool check(int k) {
    int cnt[26];
    for (int i = 0; i < s.size(); ++i)
        cnt[s[i]]++;
    int tot = 0, prev = 0;
    for (int i = 0; i < t.size(); ++i) {
        int val = cnt[t[i]] - prev;
        tot += (k + val - 1) / val;
        if (i + 1 < t.size()) {
            int took = k % val;
            int pos = lower_bound(pr[t[i] - 'a'],
            pr[t[i] - 'a'] + s.size(), took);
            prev = pr[t[i + 1] - 'a'][pos] - 
                    pr[t[i + 1] - 'a'][0];
        }
        // cnt[t[i]] -= k;
    //     for (char& c : ok) {
    //         cnt[c] -= (k - 1);
    //         if (cnt[c] < 0) return false;
    //     }
    //     for (char& c : ok) {
    //         if (c != t[i]) {
    //             cnt[c] -= pr[pos][c - 'a'];
    //             if (cnt[c] < 0) return false;
    //         }
    //     }
    }
    cerr << k << " " << tot << endl;
    return tot <= n;
}

void solve() {
    cin >> n >> s >> t;
    for (int i = 0; i < s.size(); ++i)
        pr[s[i] - 'a'][i]++;
    for (int i = 0; i < 26; ++i)
        for (int j = 1; j < s.size(); ++j)
            pr[i][j] += pr[i][j - 1];
    // for (int i = 0; i < t.size(); ++i)
    //     ok.insert(t[i]);
    int l = 0, r = n + 1;
    while (r - l > 1) {
        int m = l + (r - l) / 2;
        if (check(m)) l = m;
        else r = m;
    }
    cout << l;
}

signed main() {
    ios_base::sync_with_stdio(0); 
    cin.tie(0); cout.tie(0);

    int t = 1;
    if (MULTI_TEST) cin >> t;
    while (t--) solve();

    return 0;
}