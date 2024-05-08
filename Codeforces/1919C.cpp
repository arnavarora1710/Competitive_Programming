// https://codeforces.com/problemset/problem/1919/C
#pragma GCC optimize("Ofast")
#pragma GCC optimization("unroll-loops")

#include <bits/stdc++.h>
using namespace std;

#define int long long
typedef pair<int, int> pi;
#define f first
#define s second
#define MULTI_TEST (1)
int n, a[200005];

void solve() {
    cin >> n;
    for (int i = 0; i < n; ++i) cin >> a[i]; 
    vector<int> one = {a[0]};
    vector<int> two;
    for (int i = 1; i < n; ++i) {
        if (two.empty()) {
            if (one.back() < a[i]) two.push_back(a[i]);
            else one.push_back(a[i]);
        } else {
            if (one.back() >= a[i]) {
                if (two.back() < a[i]) {
                    // one good two bad
                    one.push_back(a[i]);
                } else {
                    // one good two good
                    if (one.back() >= two.back()) {
                        two.push_back(a[i]);
                    } else {
                        one.push_back(a[i]);
                    }
                }
            } else {
                if (two.back() >= a[i]) {
                    // two good one bad
                    two.push_back(a[i]);
                } else {
                    // two bad one bad
                    if (one.back() >= two.back()) {
                        two.push_back(a[i]);
                    } else {
                        one.push_back(a[i]);
                    }
                }
            }
        }
    }
    int ans = 0;
    for (int i = 0; i + 1 < one.size(); ++i) {
        ans += (one[i] < one[i + 1]);
    }
    for (int i = 0; i + 1 < two.size(); ++i) {
        ans += (two[i] < two[i + 1]);
    }
    cout << ans << endl;
}

signed main() {
    ios_base::sync_with_stdio(0); 
    cin.tie(0); cout.tie(0);

    int t = 1;
    if (MULTI_TEST) cin >> t;
    while (t--) solve();

    return 0;
}