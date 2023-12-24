#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
#pragma GCC optimization("unroll-loops")

#include <bits/stdc++.h>
using namespace std;

#define int long long
#define MULTI_TEST (1)
int n; vector<int> pos;

int pw(int a, int b) {
    int res = 1;
    while (b) {
        if (b&1) res = (res * a);
        a = (a * a);
        b >>= 1;
    }
    return res;
}

void solve() {
    cin >> n;
    int idx = lower_bound(pos.begin(), pos.end(), n) - pos.begin() - 1, x = pos[idx];
    int num = pw(10, idx) + (n - x) / (idx + 1);
    string a = to_string(num);
    cout << a[(n - x) % (idx + 1)] << endl;
}

signed main() {
    ios_base::sync_with_stdio(0); 
    cin.tie(0); cout.tie(0);

    pos.push_back(1); int cnt = 10, cnt1 = 1;
    for (int i = 0; i < 18; ++i)
        pos.push_back(pos.back() + cnt1 * (cnt - cnt/10)), cnt *= 10, cnt1++;
        
    int t = 1;
    if (MULTI_TEST) cin >> t;
    while (t--) solve();

    return 0;
}