// https://codeforces.com/problemset/problem/1623/C
#include <bits/stdc++.h>
using namespace std;
const int MAXN = 2e5;
int t, n, a[MAXN];

bool check(int m) {
    vector<int> cur(a, a + n);
    for (int i = n - 1; i >= 2; --i) {
        if (cur[i] < m) return false;
        int d = min(a[i], cur[i] - m) / 3;
        cur[i - 1] += d; cur[i - 2] += 2 * d;
    }
    return cur[0] >= m && cur[1] >= m;
}

int main() {
    cin >> t;
    while (t--) {
        cin >> n; for (int i = 0; i < n; ++i) cin >> a[i];
        int l = *min_element(a, a + n) - 1, r = *max_element(a, a + n) + 1;
        while (r - l > 1) {
            int m = l + (r - l) / 2;
            if (check(m)) l = m;
            else r = m;
        }
        cout << l << endl;
    }
    return 0;
}