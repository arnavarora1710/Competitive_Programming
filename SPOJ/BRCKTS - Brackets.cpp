// https://www.spoj.com/problems/BRCKTS/
#pragma GCC optimize("Ofast")
#pragma GCC optimization("unroll-loops")

#include <bits/stdc++.h>
using namespace std;

#define int long long
#define MULTI_TEST (0)
const int maxn = 30005;
int n, m, k;
char a[maxn];

struct seg {
    int trmn[4 * maxn], lz[4 * maxn]; 

    void push(int v) {
        lz[v<<1] += lz[v];
        lz[v<<1|1] += lz[v];
        trmn[v] = trmn[v] + lz[v];
        lz[v] = 0;
    }

    void pullmin(int v) {
        trmn[v] = min(trmn[v<<1] + lz[v<<1], trmn[v<<1|1] + lz[v<<1|1]);
    }
 
    int minQuery(int v, int ll, int rr, int l, int r) {
        if (l > r) return INT_MAX;
        else if (l == ll && r == rr) return lz[v] + trmn[v];
        else {
            int mm = ll + (rr - ll) / 2;
            if (lz[v]) push(v);
            int left = minQuery(v<<1, ll, mm, l, min(mm, r));
            int right = minQuery(v<<1|1, mm + 1, rr, max(mm + 1, l), r);
            pullmin(v);
            return min(left, right);
        }
    }

    void update(int v, int ll, int rr, int val, int l, int r) {
        if (l > r) return;
        else if (l == ll && r == rr) lz[v] += val;
        else {
            int mm = ll + (rr - ll) / 2;
            if (lz[v]) push(v);
            update(v<<1, ll, mm, val, l, min(mm, r));
            update(v<<1|1, mm + 1, rr, val, max(mm + 1, l), r);
            pullmin(v);
        }
    }
};

void solve(int tc) {
    scanf("%ld%s%ld", &n, a, &m);
    printf("Test %ld:\n", tc);
    seg tree;
    for (int i = 0; i < n; ++i) {
        if (a[i] == '(') tree.update(1, 0, n - 1, 1, i, n - 1);
        else tree.update(1, 0, n - 1, -1, i, n - 1);
    }
    for (int i = 0; i < m; ++i) {
        scanf("%ld", &k);
        if (!k) {
            int q1 = tree.minQuery(1, 0, n - 1, n - 1, n - 1);
            int q2 = tree.minQuery(1, 0, n - 1, 0, n - 1);
            if (q1 != 0 || q2 < 0) printf("NO\n");
            else printf("YES\n");
        }
        else {
            k--;
            if (a[k] == '(') {
                tree.update(1, 0, n - 1, -2, k, n - 1);
                a[k] = ')';
            }
            else {
                tree.update(1, 0, n - 1, 2, k, n - 1);
                a[k] = '(';
            }
        }
    }
}

signed main() {
    ios_base::sync_with_stdio(0); 
    cin.tie(0); cout.tie(0);

    int t = 10;
    if (MULTI_TEST) cin >> t;
    for (int i = 1; i <= t; ++i) solve(i);

    return 0;
}