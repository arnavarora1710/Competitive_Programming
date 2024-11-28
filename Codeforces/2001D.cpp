// https://codeforces.com/contest/2001/problem/D
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
#define MULTI_TEST (1)

typedef pair<int, int> pi;
typedef vector<int> vi;
typedef vector<vector<int>> vii;

const int N = 300005, INF = 1e18, MOD = 1e9 + 7;
int n, k, q, x, y, u, v, a[N];

void solve() {
    cin >> n;
    for (int i = 0; i < n; ++i) cin >> a[i];
    vi ans, cnt(n + 1), vis(n + 1), ind(n + 1, -1);
    for (int i = 0; i < n; ++i) cnt[a[i]]++;
    int last = -1;
    for (int i = 0; i < n; ++i) {
        if (!vis[a[i]]) {
            vis[a[i]] = true;
            int sz = ans.size();
            int index = -1;
            for (int j = last + 1, cnt = 0; j < sz && cnt < 1000; ++j, ++cnt) {
                if (j&1) {
                    if (a[i] < ans[j]) {
                        index = j;
                        break;
                    }
                } else {
                    if (a[i] > ans[j]) {
                        index = j;
                        break;
                    }
                }
            }
            if (index == -1) {
                ans.push_back(a[i]);
            } else {
                int x = ans[index];
                while (ans.back() != x) {
                    vis[ans.back()] = false;
                    ind[ans.back()] = -1;
                    ans.pop_back();
                }
                vis[x] = false;
                ind[x] = -1;
                ans.back() = a[i];
            }
            ind[a[i]] = ans.size() - 1;
        }
        cnt[a[i]]--;
        if (!cnt[a[i]])
            last = max(last, ind[a[i]]);
    }
    cout << ans.size() << '\n';
    for (auto& x : ans) cout << x << ' ';
    cout << '\n';
}

signed main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int Q = 1; if (MULTI_TEST) cin >> Q;
    while (Q--) solve();
}