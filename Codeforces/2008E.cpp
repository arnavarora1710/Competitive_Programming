// https://codeforces.com/contest/2008/problem/E
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

const int N = 200005, INF = 1e18, MOD = 1e9 + 7;
int n, k, q, x, y, u, v, a[N];
string s;

void solve() {
    cin >> n >> s;
    int ans = INF;
    vi p1(n), p2(n);
    for (int i = 0; i < 26; ++i) {
        for (int j = 0; j < 26; ++j) {
            int cnt = (n&1 ? INF : 0);
            for (int k = 0; k < n; ++k) {
                int w1 = 0, w2 = 0;
                if (k&1) w1 += (s[k] != 'a' + i), w2 += (s[k] != 'a' + j);
                else w1 += (s[k] != 'a' + j), w2 += (s[k] != 'a' + i);
                if (n % 2 == 0) cnt += w1;
                p1[k] = (k ? p1[k - 1] : 0) + w1;
                p2[k] = (k ? p2[k - 1] : 0) + w2; 
            }
            if (n&1) {
                for (int k = 0; k < n; ++k) {
                    int one = (k ? p2[k - 1] : 0);
                    int two = p1.back() - p1[k];
                    cnt = min(cnt, one + two + 1);
                }
            }
            ans = min(ans, cnt);
        }
    }
    cout << ans << '\n';
}

signed main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int Q = 1; if (MULTI_TEST) cin >> Q;
    while (Q--) solve();
}