#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

template<class T> using oset = tree<T, null_type, less<T>, rb_tree_tag,tree_order_statistics_node_update>;
template<class T> using omset = tree<T, null_type, less_equal<T>, rb_tree_tag,tree_order_statistics_node_update>;

#define int long long
#define f first
#define s second
#define MULTI_TEST (0)

typedef pair<int, int> pi;
typedef vector<int> vi;
typedef vector<vector<int>> vii;

const int N = 2e6, INF = 1e18, MOD = 1e9 + 7;
int n, m, c, k, q, x, y, u, v, a[N];

struct MaxQueue {
    stack<pair<int, int>> s1, s2;
    void add(int ele) {
        int mx = s1.empty() ? ele : max(ele, s1.top().second);
        s1.push({ele, mx});
    }
    void remove(int ele) {
        if (s2.empty()) {
            while (!s1.empty()) {
                int ele = s1.top().first;
                s1.pop();
                int mx = s2.empty() ? ele : max(ele, s2.top().second);
                s2.push({ele, mx});
            }
        }
        s2.pop();
    }
    int query() {
        if (s1.empty() || s2.empty()) 
            return s1.empty() ? s2.top().second : s1.top().second;
        else
            return max(s1.top().second, s2.top().second);
    }
};

struct MinQueue {
    stack<pair<int, int>> s1, s2;
    void add(int ele) {
        int mn = s1.empty() ? ele : min(ele, s1.top().second);
        s1.push({ele, mn});
    }
    void remove(int ele) {
        if (s2.empty()) {
            while (!s1.empty()) {
                int ele = s1.top().first;
                s1.pop();
                int mn = s2.empty() ? ele : min(ele, s2.top().second);
                s2.push({ele, mn});
            }
        }
        s2.pop();
    }
    int query() {
        if (s1.empty() || s2.empty()) 
            return s1.empty() ? s2.top().second : s1.top().second;
        else
            return min(s1.top().second, s2.top().second);
    }
};

void solve() {
    cin >> n >> m >> c;
    for (int i = 0; i < n; ++i) cin >> a[i];
    MaxQueue mx = *(new MaxQueue());
    MinQueue mn = *(new MinQueue());
    for (int i = 0; i < m; ++i) {
        mx.add(a[i]); mn.add(a[i]);
    }
    vi ans;
    int l = 0, r = m;
    for (; r < n; ++l, ++r) {
        if (mx.query() - mn.query() <= c) ans.push_back(l);
        mx.remove(a[l]); mn.remove(a[l]);
        mx.add(a[r]); mn.add(a[r]);
    }
    if (mx.query() - mn.query() <= c) ans.push_back(l);
    if (ans.empty()) cout << "NONE";
    else for (auto& x : ans) cout << x + 1 << '\n';
}

signed main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int Q = 1; if (MULTI_TEST) cin >> Q;
    while (Q--) solve();
}