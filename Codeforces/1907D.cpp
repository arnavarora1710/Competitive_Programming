// https://codeforces.com/contest/1907/problem/D
#pragma GCC optimize("Ofast")
#pragma GCC optimization("unroll-loops")

#include <bits/stdc++.h>
using namespace std;

#define int long long
#define f first
#define s second
typedef pair<int, int> pi;
#define MULTI_TEST (1)
int N, l, r;
vector<pi> A;

bool check(int m) {
    int ll = 0, rr = 0;
    for (auto pp : A) {
        ll = max(ll - m, pp.f);
        rr = min(rr + m, pp.s);
        if (ll > rr) return false;
    }
    return true;
}

void solve() {
    cin >> N; A.clear();
    A.push_back({0, 0});
    for (int i = 0; i < N; ++i) {
        cin >> l >> r;
        A.push_back({l, r});
    }
    int l = -1, r = 1e15;
    while (r - l > 1) {
        int m = l + (r - l) / 2;
        if (!check(m)) l = m;
        else r = m;
    }
    cout << r << endl;
}

signed main() {
    ios_base::sync_with_stdio(0); 
    cin.tie(0); cout.tie(0);

    int t = 1;
    if (MULTI_TEST) cin >> t;
    while (t--) solve();

    return 0;
}