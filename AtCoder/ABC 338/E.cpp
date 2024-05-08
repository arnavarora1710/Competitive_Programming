#include <bits/stdc++.h>
using namespace std;

const int maxn = 200005;
int N, x, y, seg[8 * maxn];

int sum(int v, int ll, int rr, int l, int r) {
    if (l > r) return 0;
    if (ll == l && rr == r) return seg[v];
    int mm = ll + (rr - ll) / 2;
    return sum(v<<1, ll, mm, l, min(mm, r)) + sum(v<<1|1, mm + 1, rr, max(mm + 1, l), r);
}

void update(int v, int ll, int rr, int val, int pos) {
    if (ll == rr) seg[v] = val;
    else {
        int mm = ll + (rr - ll) / 2;
        if (pos <= mm) update(v<<1, ll, mm, val, pos);
        else update(v<<1|1, mm + 1, rr, val, pos);
        seg[v] = seg[v<<1] + seg[v<<1|1];
    }
}

int main() {
    cin >> N;
    bool ok = 0;
    for (int i = 0; i < N; ++i) {
        cin >> x >> y;
        if (x > y) swap(x, y);
        if (sum(1, 1, 2 * N, x, y) != 0) ok = 1;
        update(1, 1, 2 * N, 1, x);
        update(1, 1, 2 * N, -1, y);
    }
    if (ok) cout << "Yes";
    else cout << "No";
}
