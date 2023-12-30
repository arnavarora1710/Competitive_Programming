#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
#pragma GCC optimization("unroll-loops")

#include <bits/stdc++.h>
using namespace std;

#define int long long
typedef pair<int, int> pi;
#define f first
#define s second
#define MULTI_TEST (0)
int n, k, a[1005];

void solve() {
    cin >> n >> k; for (int i = 0; i < n; ++i) cin >> a[i];
    map<int, pi> m;
    for (int i = 0; i < n; ++i) {
		for (int j = i + 1; j < n; j++) {
			int idx = k - a[i] - a[j];
			if (m.count(idx)) {
				cout << i + 1 << " " << j + 1 << " " << m[idx].f + 1 << " " << m[idx].s + 1;
				return;
			}
		}
        for (int j = 0; j < i; j++) m[a[i] + a[j]] = {i, j};
	}
	cout << "IMPOSSIBLE";
}

signed main() {
    ios_base::sync_with_stdio(0); 
    cin.tie(0); cout.tie(0);

    int t = 1;
    if (MULTI_TEST) cin >> t;
    while (t--) solve();

    return 0;
}