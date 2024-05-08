// https://codeforces.com/contest/1944/problem/C
#pragma GCC optimize("Ofast")
#pragma GCC optimization("unroll-loops")

#include <bits/stdc++.h>
using namespace std;

#define int long long
typedef pair<int, int> pi;
#define f first
#define s second
#define MULTI_TEST (1)
const int inf = 1e18;
int n, a[200005], cnt[200005];
vector<int> ones;

void solve() {
    cin >> n;
    for (int i = 0; i < n; ++i) cin >> a[i];
    sort(a, a + n); memset(cnt, 0, sizeof(cnt));
    ones.clear();
    for (int i = 0; i < n; ++i) cnt[a[i]]++;
    int id = inf;
    for (int i = 0; i < n; ++i) {
        if (cnt[i] == 1) ones.push_back(i);
        else if (cnt[i] == 0) id = min(id, i);
    }
    if (ones.size() >= 2) cout << min(id, ones[1]) << endl;
    else cout << (id == inf ? n : id) << endl;
}

signed main() {
    ios_base::sync_with_stdio(0); 
    cin.tie(0); cout.tie(0);

    int t = 1;
    if (MULTI_TEST) cin >> t;
    while (t--) solve();

    return 0;
}