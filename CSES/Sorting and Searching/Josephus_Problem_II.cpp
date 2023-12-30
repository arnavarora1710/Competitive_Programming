#pragma GCC optimize("Ofast")
#pragma GCC optimization("unroll-loops")

#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;
template<class T> using oset =tree<T, null_type, less<T>, rb_tree_tag,tree_order_statistics_node_update>;

#define int long long
#define MULTI_TEST (0)
int n, k;

void solve() {
    cin >> n >> k;
    int mover = k % n;
    oset<int> s; for (int i = 1; i <= n; ++i) s.insert(i);
    while (s.size()) {
        int remover = *s.find_by_order(mover);
        s.erase(remover);
        if (s.size()) {
            mover = (mover + k) % (s.size());
        }
        cout << remover << " ";
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