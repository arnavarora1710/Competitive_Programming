#pragma GCC optimize("Ofast")
#pragma GCC optimization("unroll-loops")

#include <bits/stdc++.h>
using namespace std;

#define int long long
typedef pair<int, int> pi;
#define f first
#define s second
int n, t, x, y;
map<int, int> cnt, ind;

void solve() {
    cin >> n >> t;
    for (int i = 1; i <= n; ++i)
        cnt[0]++, ind[i] = 0; 
    for (int i = 0; i < t; ++i) {
        cin >> x >> y;
        cnt[ind[x]]--;
        if (!cnt[ind[x]])
            cnt.erase(ind[x]);
        ind[x] += y, cnt[ind[x]]++;
        cout << cnt.size() << endl;
    }
}

signed main() {
    ios_base::sync_with_stdio(0); 
    cin.tie(0); cout.tie(0);
    solve();
}