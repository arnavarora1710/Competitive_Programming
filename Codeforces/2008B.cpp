// https://codeforces.com/contest/2008/problem/B
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
    int sq = sqrt(n);
    if (sq * sq != n) cout << "No\n";
    else {
        vector<vector<char>> b(sq, vector<char>(sq));
        int k = 0;
        for (int i = 0; i < sq; ++i) {
            for (int j = 0; j < sq; ++j) {
                b[i][j] = s[k++];
            }
        }
        for (int i = 0; i < sq; ++i) {
            if (b[0][i] == '0' || b[sq - 1][i] == '0') {
                cout << "No\n";
                return;
            }
        }
        for (int i = 1; i + 1 < sq; ++i) {
            if (b[i][0] != '1' || b[i][sq - 1] != '1') {
                cout << "No\n";
                return;
            }
            for (int j = 1; j + 1 < sq; ++j) {
                if (b[i][j] != '0') {
                    cout << "No\n";
                    return;
                }
            }
        }
        cout << "Yes\n";
    }
}

signed main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int Q = 1; if (MULTI_TEST) cin >> Q;
    while (Q--) solve();
}