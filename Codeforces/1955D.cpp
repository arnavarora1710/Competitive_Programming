#include <bits/stdc++.h>
using namespace std;

#define int long long

const int maxn = 2e6 + 5, maxct = 2e6 + 5;

int n, m, k, a[maxn], b[maxn], b_count[maxct], window_count[maxct];

void solve() {
    scanf("%lld%lld%lld", &n, &m, &k);
    memset(b_count, 0, sizeof(b_count));
    memset(window_count, 0, sizeof(window_count));
    for (int i = 0; i < n; ++i) scanf("%lld", &a[i]);
    for (int i = 0; i < m; ++i) {
        scanf("%lld", &b[i]);
        b_count[b[i]]++;
    }
    
    int count = 0;
    int good_elements = 0;

    for (int j = 0; j < m; ++j) {
        window_count[a[j]]++;
        if (window_count[a[j]] <= b_count[a[j]]) 
            good_elements++;
    }
    
    if (good_elements >= k) count++;

    for (int j = 1; j <= n - m; ++j) {
        window_count[a[j - 1]]--;
        if (window_count[a[j - 1]] < b_count[a[j - 1]])
            good_elements--;

        window_count[a[j + m - 1]]++;
        if (window_count[a[j + m - 1]] <= b_count[a[j + m - 1]])
            good_elements++;

        if (good_elements >= k) count++;
    }
    
    printf("%lld\n", count);
}

signed main() {
    int t = 1;
    scanf("%lld", &t);
    while (t--) solve();

    return 0;
}