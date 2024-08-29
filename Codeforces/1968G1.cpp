// https://codeforces.com/contest/1968/problem/G1
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
#define print(a) for (auto& x : (a)) cerr << x << ' '; cerr << '\n';
#define MULTI_TEST (1)

typedef pair<int, int> pi;
typedef vector<int> vi;
typedef vector<vector<int>> vii;

const int N = 200005, INF = 1e18, MOD = 1e9 + 7;
int n, k, q, x, y, u, v, a[N];
string s;

vector<int> compute_pi(string& pat) {
    int n = pat.length();
    vector<int> pi(n);
    pi[0] = 0;
    for (int i = 1; i < n; i++) {
        pi[i] = 0;
        int j = pi[i - 1]; /* trying length j + 1 */
        while (j > 0 && pat[j] != pat[i]) {
            j = pi[j - 1];
        }
        if (pat[j] == pat[i]) {
            pi[i] = j + 1;
        }
    }
    return pi;
}

vector<int> find_matches(string& text, string& pat) {
    int n = pat.length(), m = text.length();
    string s = pat + "$" + text;
    vector<int> pi = compute_pi(s), ans;
    for (int i = n + 1; i <= n + m; i++) {
        if (pi[i] == n) {
            ans.push_back(i - 2 * n);
        }
    }
    return ans;
}

bool check(int m) {
    string S = s;
    string T;
    for (int i = 0; i < m; ++i) T.push_back(s[i]);
    vi kmp = find_matches(S, T);
    int cnt = 0, p = -1;
    for (int i = 0; i < kmp.size(); ++i) {
        if (kmp[i] > p) {
            cnt++;
            p = kmp[i] + m - 1;
        }
    }
    return cnt >= x;
}

void solve() {
    cin >> n >> x >> x >> s;
    int l = 0, r = n + 1;
    while (r - l > 1) {
        int m = l + (r - l) / 2;
        if (check(m)) l = m;
        else r = m;
    }
    cout << l << '\n';
}

signed main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int Q = 1; if (MULTI_TEST) cin >> Q;
    while (Q--) solve();
}