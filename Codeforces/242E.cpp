// https://codeforces.com/problemset/problem/242/E
#pragma GCC optimize("Ofast")
#pragma GCC optimization("unroll-loops")

#include <bits/stdc++.h>
using namespace std;

#define MULTI_TEST (0)
typedef long long llong;
int n, q, tp, q1, q2, q3;
vector<int> a;

struct Pair {
    llong sum;
    vector<int> count1;
    Pair() {}
    Pair(int s) {
        sum = s;
        count1.resize(20);
        for (int i = 0; i < 20; ++i) {
            if (s & (1 << i)) count1[i] = 1;
        }
    }
    Pair(Pair l, Pair r) {
        sum = l.sum + r.sum;
        count1.resize(20);
        for (int i = 0; i < 20; ++i)
            count1[i] = l.count1[i] + r.count1[i];  
    }
};

vector<Pair> tr;
vector<int> lz;

void build(int v, int ll, int rr) {
    if (ll == rr) tr[v] = *(new Pair(a[ll]));
    else{
        int mm = ll + (rr - ll) / 2;
        build(v<<1, ll, mm);
        build(v<<1|1, mm + 1, rr);
        tr[v] = *(new Pair(tr[v<<1], tr[v<<1|1]));
    }
}

void push(int v, int l, int r) {
    if (!lz[v]) return;
    if (l == r) {
        tr[v] = *(new Pair(tr[v].sum ^ lz[v]));
        lz[v] = 0;
    } else {
        lz[v<<1] ^= lz[v];
        lz[v<<1|1] ^= lz[v];
        llong len = r - l + 1;
        for (llong i = 0; i < 20; ++i) {
            if (lz[v] & (1 << i)) {
                llong d = (len - tr[v].count1[i]) - (tr[v].count1[i]);
                tr[v].sum += (1 << i) * d;
                tr[v].count1[i] = len - tr[v].count1[i];
            }
        }
        lz[v] = 0;
    }
}

llong query(int v, int ll, int rr, int l, int r) {
    push(v, ll, rr);
    if (rr < l || r < ll) return 0;
    if (l <= ll && rr <= r) return tr[v].sum;
    else {
        int mm = ll + (rr - ll) / 2;
        llong left = query(v<<1, ll, mm, l, r);
        llong right = query(v<<1|1, mm + 1, rr, l, r);
        return left + right;
    }
}

void update(int v, int ll, int rr, int val, int l, int r) {
    push(v, ll, rr);
    if (rr < l || r < ll) return;
    if (l <= ll && rr <= r) {
        lz[v] ^= val;
        push(v, ll, rr);
    } else {
        int mm = ll + (rr - ll) / 2;
        update(v<<1, ll, mm, val, l, r);
        update(v<<1|1, mm + 1, rr, val, l, r);
        tr[v] = *(new Pair(tr[v<<1], tr[v<<1|1]));
    }
}

void solve() {
    cin >> n;
    a.resize(n);
    tr.resize(4*n);
    lz.resize(4*n);
    for (int i = 0; i < n; ++i) cin >> a[i];
    build(1, 0, n - 1);
    cin >> q;
    for (int i = 0; i < q; ++i) {
        cin >> tp >> q1 >> q2; q1--, q2--;
        if (tp == 1) 
            cout << query(1, 0, n - 1, q1, q2) << '\n';
        else {
            cin >> q3;
            update(1, 0, n - 1, q3, q1, q2);
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0); 
    cin.tie(0); cout.tie(0);

    int t = 1;
    if (MULTI_TEST) cin >> t;
    while (t--) solve();

    return 0;
}
