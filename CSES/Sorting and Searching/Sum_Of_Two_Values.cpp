#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pi;

const int MAXN = 2e5;
int n, x; pi a[MAXN];

int main() {
    cin >> n >> x; for (int i = 0; i < n; ++i) cin >> a[i].first, a[i].second = i + 1;
    sort(a, a + n);
    for (int i = 0; i < n; ++i) {
        int idx = lower_bound(a , a + n, make_pair(x - a[i].first, INT_MIN)) - a;
        if (idx >= 0 && idx < n && a[idx].first == x - a[i].first && a[idx].second != a[i].second) {
            cout << a[i].second << " " << a[idx].second; return 0;
        }
    }
    cout << "IMPOSSIBLE";
    return 0;
}