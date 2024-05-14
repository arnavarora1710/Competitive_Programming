// https://codeforces.com/problemset/problem/1660/D
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
int N, a[maxn];
vector<pair<int, pi>> ans;

void add(int z1, int z2, int L, int R) {
    if (z1 > z2) return;

    vector<int> b;
    int cnt = 0;
    bool zero = 0;
    for (int i = z1; i <= z2; ++i) {
        zero = zero || (a[i] == 0);
        cnt += (a[i] < 0);
        b.push_back(a[i]);
    }
    if (zero) return;
    
    int n = b.size();

    if (cnt&1) {
        int i = 0, j = n - 1;
        for (; i < n; ++i)  
            if (b[i] < 0) break;
        for (; j >= 0; --j)
            if (b[j] < 0) break;

        // delete left
        int cnt12 = 0;
        for (int k = i + 1; k < n; ++k) {
            cnt12 += (abs(b[k]) == 2);
        }
        // delete right
        int cnt22 = 0;
        for (int k = 0; k < j; ++k) {
            cnt22 += (abs(b[k]) == 2);
        }
        if (cnt12 > cnt22) {
            L += i + 1;
            ans.push_back({cnt12, {L, R}});
        } else {
            R += n - j;
            ans.push_back({cnt22, {L, R}});
        }
    } else {
        int cnt2 = 0;
        for (int i = 0; i < n; ++i) {
            cnt2 += (abs(b[i]) == 2);
        }
        ans.push_back({cnt2, {L, R}});
    }

}

void solve() {
    int n; cin >> n; N = n;
    for (int i = 0; i < n; ++i) cin >> a[i];
    ans.clear();
    ans.push_back({0, {n, 0}});

    vector<int> zeros;
    for (int i = 0; i < n; ++i)
        if (a[i] == 0) 
            zeros.push_back(i);

    add(0, n - 1, 0, 0);
    if (zeros.size()) 
        add(0, zeros[0] - 1, 0, n - zeros[0]);
    for (int i = 0; i + 1 < zeros.size(); ++i) {
        int z1 = zeros[i];
        int z2 = zeros[i + 1];
        add(z1 + 1, z2 - 1, z1 + 1, n - z2);
    }
    if (zeros.size())
        add(zeros.back() + 1, n - 1, zeros.back() + 1, 0);

    sort(ans.begin(), ans.end());
    reverse(ans.begin(), ans.end());

    int L = ans[0].s.f, R = ans[0].s.s;
    cout << L << ' ' << R << '\n';
}

signed main() {
    ios_base::sync_with_stdio(0); 
    cin.tie(0); cout.tie(0);

    int t = 1;
    if (MULTI_TEST) cin >> t;
    while (t--) solve();

    return 0;
}