// https://codeforces.com/contest/2013/problem/C
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

bool ask(string s) {
    cout << "? " << s << endl;
    int x; cin >> x;
    return x;
}

void solve() {
    cin >> n;
    if (n == 1) {
        if (ask("1")) cout << "! 1" << endl;
        else cout << "! 0" << endl;
        return;
    }
    string ans = "10";
    if (ask(ans)) {
        for (int len = 3; len <= n; ++len) {
            string t1 = ans, t0 = ans;
            t1 += "1"; t0 += "0";
            bool one = ask(t1);
            bool zero = ask(t0);
            if (one) ans += "1";
            else if (zero) ans += "0";
            else break;
        }
        while (ans.size() < n) {
            string t1 = ans, t0 = ans;
            t1 = "1" + ans; t0 = "0" + ans;
            bool one = ask(t1);
            bool zero = ask(t0);
            if (one) ans = "1" + ans;
            else if (zero) ans = "0" + ans;
        }
        cout << "! " << ans << endl;
    } else {
        if (ask("1")) {
            if (ask("0")) {
                string ans = "00";
                while (ask(ans)) ans += "0";
                ans.pop_back();
                ans += "1";
                while (ans.size() < n) ans += "1";
                cout << "! " << ans << endl;
            } else {
                string result(n, '1');
                cout << "! " << result << endl;
            }
        }
        else {
            string result(n, '0');
            cout << "! " << result << endl;
        }
    }
}

signed main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int Q = 1; if (MULTI_TEST) cin >> Q;
    while (Q--) solve();
}