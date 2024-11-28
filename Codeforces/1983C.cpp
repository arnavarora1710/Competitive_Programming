// https://codeforces.com/contest/1983/problem/C
#pragma GCC optimize("Ofast")
#pragma GCC optimization("unroll-loops")

#include <bits/stdc++.h>
using namespace std;

#define int long long
typedef pair<int, int> pi;
#define f first
#define s second
#define mp make_pair
#define MULTI_TEST (1)
const int maxn = 2e5 + 5, inf = 1e18;
int n, a[maxn], b[maxn], c[maxn];

bool cmp(vector<int> d, vector<int> e) {
    return d == e;
}

void solve() {
    cin >> n;
    for (int i = 0; i < n; ++i) cin >> a[i];    
    for (int i = 0; i < n; ++i) cin >> b[i];
    for (int i = 0; i < n; ++i) cin >> c[i];
    int sum = 0;
    for (int i = 0; i < n; ++i) sum += a[i];
    vector<int> pra(n + 2), prb(n + 2), prc(n + 2), sufa(n + 2), sufb(n + 2), sufc(n + 2);
    for (int i = 0; i < n; ++i) {
        pra[i] = (i ? pra[i - 1] : 0) + a[i];
        prb[i] = (i ? prb[i - 1] : 0) + b[i];
        prc[i] = (i ? prc[i - 1] : 0) + c[i];
    }
    for (int i = n - 1; i >= 0; --i) {
        sufa[i] = (i + 1 < n ? sufa[i + 1] : 0) + a[i];
        sufb[i] = (i + 1 < n ? sufb[i + 1] : 0) + b[i];
        sufc[i] = (i + 1 < n ? sufc[i + 1] : 0) + c[i];
    }
    vector<int> order = {0, 1, 2};
    for (int i = 0; i < n; ++i) {
        sort(order.begin(), order.end());
        do {
            // for (int j : order) cerr << j << ' ';
            // cerr << '\n';
            int sum1, sum2, sum3, l1, r1, l2, r2, l3, r3;
            if (order[0] == 0) sum1 = pra[i], l1 = 0, r1 = i;
            else if (order[1] == 0) sum1 = prb[i], l2 = 0, r2 = i;
            else if (order[2] == 0) sum1 = prc[i], l3 = 0, r3 = i;

            int l = i, r = n;
            while (r - l > 1) {
                int m = l + (r - l) / 2;
                int val;
                if (order[0] == 1) val = pra[m] - pra[i];
                else if (order[1] == 1) val = prb[m] - prb[i];
                else if (order[2] == 1) val = prc[m] - prc[i];
                if (val < (sum + 2) / 3) l = m;
                else r = m;
            }
            if (order[0] == 1) sum2 = pra[r] - pra[i], l1 = i + 1, r1 = r;
            else if (order[1] == 1) sum2 = prb[r] - prb[i], l2 = i + 1, r2 = r;
            else if (order[2] == 1) sum2 = prc[r] - prc[i], l3 = i + 1, r3 = r;

            if (order[0] == 2) sum3 = sufa[r + 1], l1 = r + 1, r1 = n - 1;
            else if (order[1] == 2) sum3 = sufb[r + 1], l2 = r + 1, r2 = n - 1;
            else if (order[2] == 2) sum3 = sufc[r + 1], l3 = r + 1, r3 = n - 1;

            // if (i == 0 && cmp(order, {0, 1, 2}))
            //     cerr << sum1 << ' ' << sum2 << ' ' << sum3 << '\n';
            int tot = (sum + 2) / 3;
            l1++, r1++, l2++, r2++, l3++, r3++;
            if (sum1 >= tot && sum2 >= tot && sum3 >= tot) {
                cout << l1 << ' ' << r1 << ' ' << l2 << ' ' << r2 << ' ' << l3 << ' ' << r3 << '\n';
                return;
            }
        } while (next_permutation(order.begin(), order.end()));
    }
    cout << -1 << '\n';
}

signed main() {
    ios_base::sync_with_stdio(0); 
    cin.tie(0); cout.tie(0);

    int t = 1;
    if (MULTI_TEST) cin >> t;
    while (t--) solve();

    return 0;
}
