// https://codeforces.com/contest/1856/problem/C
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
int n, k, a[maxn];
// 1) think as a histogram?
// 2) bsta?
// on max after at most k iterations
// if can(m), then can(m - 1)
// can you make a[i + 1] -> >= m - 1
// 3) iterate over the end element
// if you have increasing seq, then you can see 
// at max where can the values behind go upto

bool check(int m) {
    for (int i = n - 2; i >= 0; --i) {
        int kk = k, want = m, j = i;
        while (j < n) {
            if (a[j] >= want) return true;    
            else {
                int diff = want - a[j];
                if (kk - diff < 0) break;
                kk -= diff, want--, j++;
            }
        }
    }
    return false;
}

void solve() {
    cin >> n >> k;
    for (int i = 0; i < n; ++i) cin >> a[i];
    int mx = 0;
    for (int i = 0; i < n; ++i) mx = max(mx, a[i]);
    int l = -1, r = 3e8;
    while (r - l > 1) {
        int m = l + (r - l) / 2;
        if (check(m)) l = m;
        else r = m;
    }
    cout << max(mx, l) << endl;
}

signed main() {
    ios_base::sync_with_stdio(0); 
    cin.tie(0); cout.tie(0);

    int t = 1;
    if (MULTI_TEST) cin >> t;
    while (t--) solve();

    return 0;
}