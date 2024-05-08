// https://codeforces.com/contest/1742/problem/F
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
int q, d, k, occs[26], occt[26];
string x; 

void submit(bool yes) {
	cout << (yes ? "YES\n" : "NO\n");
}

void solve() {
	cin >> q;
	memset(occs, 0, 26);
	memset(occt, 0, 26);
	char mn = 'a', mx = 'a', mxs = 'a';
	while (q--) {
		cin >> d >> k >> x;
		if (d == 1) 
			for (char c : x) mn = min(mn, c), mxs = max(mxs, c), occs[c - 'a'] += k;
		else 
			for (char c : x) mx = max(mx, c), occt[c - 'a'] += k;
		int len = occs[mn - 'a'], len1 = occt[mx - 'a'];
		if (mn == mx) submit(len < len1 && mxs == 'a');
		else submit(1);
	}
}

signed main() {
    ios_base::sync_with_stdio(0); 
    cin.tie(0); cout.tie(0);

    int t = 1;
    if (MULTI_TEST) cin >> t;
    while (t--) solve();

    return 0;
}