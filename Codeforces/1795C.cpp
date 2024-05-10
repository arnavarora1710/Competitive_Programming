// https://codeforces.com/problemset/problem/1795/C
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
int n, a[maxn], b[maxn];

// a = [10, 20, 15]
// b = [9, 8, 6]
// p = [9, 17, 23]

// i = 0 : min(10, 9) = 9 ; 10 - 9 = 1
// -> (9 * 1 = 9) - something
// i = 1 : min(20, 8) + min(1, 8) = 9 ; 20 - 8 = 12, 1 - 1 = 0
// -> (8 * 2 = 16) - something 
// i = 2 : min(15, 6) + min(12, 6) + min(0, 6) = 12 ; 15 - 6 = 9, 12 - 6 = 6, 0 - 0 = 0
// -> (6 * 3 = 18) - something 

void solve() {
    cin >> n; 
    for (int i = 0; i < n; ++i) cin >> a[i];
    for (int i = 0; i < n; ++i) cin >> b[i];
    
    vector<int> pr(n + 1);
    for (int i = 0; i < n; ++i) pr[i + 1] = pr[i] + b[i];

    vector<int> cnt(n + 1), add(n + 1);
    for (int i = 0; i < n; ++i) {
        int j = upper_bound(pr.begin(), pr.end(), a[i] + pr[i]) - pr.begin() - 1;
        cnt[i]++, cnt[j]--;
        add[j] += a[i] - pr[j] + pr[i];
    }
    for (int i = 0; i < n; ++i) {
        cout << cnt[i] * b[i] + add[i] << " ";
        cnt[i + 1] += cnt[i];
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