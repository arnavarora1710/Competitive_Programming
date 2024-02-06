// https://codeforces.com/contest/1557/problem/D
#pragma GCC optimize("Ofast")
#pragma GCC optimization("unroll-loops")

#include <bits/stdc++.h>
using namespace std;

#define int long long
#define f first
#define s second
#define MULTI_TEST (0)
typedef pair<int, int> pi;
int n, m, row, l, r; set<int> coords;
vector<vector<pi>> adj;
vector<int> bcktrck;
vector<bool> vis;

struct seg {
    vector<pi> tr, lz;

    seg (int n) {
        tr.assign(4 * n + 1, {0, -1});
        lz.assign(4 * n + 1, {0, -1});
    }

    void push(int v) {
        if (lz[v].s == -1) return;
        lz[v<<1] = lz[v];
        lz[v<<1|1] = lz[v];
        tr[v<<1] = lz[v];
        tr[v<<1|1] = lz[v];
        lz[v] = {0, -1};
    }

    pi query(int v, int ll, int rr, int l, int r) {
        if (l > r) return {0, -1};
        else if (ll == l && rr == r) return tr[v];
        else {
            push(v);
            int mm = ll + (rr - ll) / 2;
            pi left = query(v<<1, ll, mm, l, min(mm, r));
            pi right = query(v<<1|1, mm + 1, rr, max(mm + 1, l), r);
            if (left.f > right.f) return left;
            else return right;
        }
    }

    void update(int v, int ll, int rr, pi val, int l, int r) {
        if (l > r) return;
        else if (ll == l && rr == r) {
            tr[v] = val; lz[v] = val;
        } else {
            push(v);
            int mm = ll + (rr - ll) / 2;
            update(v<<1, ll, mm, val, l, min(mm, r));
            update(v<<1|1, mm + 1, rr, val, max(mm + 1, l), r);
            pi left = tr[v<<1];
            pi right = tr[v<<1|1];
            if (left.f > right.f) tr[v] = tr[v<<1];
            else tr[v] = tr[v<<1|1];
        }
    }
};

void solve() {
    cin >> n >> m; 
    adj.resize(n); vis.resize(n); bcktrck.resize(n, INT_MIN);
    for (int i = 0; i < m; ++i) {
        cin >> row >> l >> r; 
        --row, --l, --r;
        coords.insert(l);
        coords.insert(r);
        adj[row].push_back({l, r});
    }

    // coord compression
    map<int, int> mp;
    for (auto& co : coords) mp[co] = mp.size();
    for (auto& v : adj)
        for (auto& p : v) p = {mp[p.f], mp[p.s]};

    // do the seg tree
    seg tree = *(new seg(mp.size()));
    
    for (int i = 0; i < n; ++i) {
        int ans = 0, index = i;

        // query the seg tree to get max rows on range
        // but placed before this iteration
        for (auto p : adj[i]) {
            pi res = tree.query(1, 0, mp.size() - 1, p.f, p.s);
            if (res.f > ans) {
                ans = res.f;
                bcktrck[i] = res.s;
            }
        }

        // update the seg tree so you add one to the max
        // (basically connect a row at the end)
        // (also trivially handles edge case where ans = 0
        // because we need to connect 1 anyways)
        for (auto p : adj[i]) 
            tree.update(1, 0, mp.size() - 1, {ans + 1, index}, p.f, p.s);
    }
    
    // query max on the entire range
    // this gives me the rows needed
    pi ans = tree.query(1, 0, mp.size() - 1, 0, mp.size() - 1);

    // get the number of rows needed
    // and subtract that from the total number of rows
    // to get the rows not needed
    cout << n - ans.f << endl;

    // backtrack to get the rows needed
    while (ans.s != INT_MIN) {
        vis[ans.s] = true; ans.s = bcktrck[ans.s];
    }

    // print out the rows not needed
    for (int i = 0; i < n; ++i)
        if (!vis[i]) cout << i + 1 << " ";
}

signed main() {
    ios_base::sync_with_stdio(0); 
    cin.tie(0); cout.tie(0);

    int t = 1;
    if (MULTI_TEST) cin >> t;
    while (t--) solve();

    return 0;
}