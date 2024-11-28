// https://codeforces.com/contest/1991/problem/D
#pragma GCC optimize("Ofast")
#pragma GCC optimization("unroll-loops")

#include <bits/stdc++.h>
using namespace std;

#define int long long
typedef pair<int, int> pi;
#define f first
#define s second
#define mp make_pair
#define MULTI_TEST (1)
const int maxn = 2e2 + 5, inf = 1e18;
int n;

void solve() {
    cin >> n;
    if (n < 6) {
        if (n == 1) cout << "1\n1\n";
        else if (n == 2) cout << "2\n1 2\n";
        else if (n == 3) cout << "2\n1 2 2\n";
        else if (n == 4) cout << "3\n1 2 2 3\n";
        else cout << "3\n1 2 2 3 3\n";
    } else {
        vector<int> ans;
        for (int i = 1; i <= n; ++i)
            ans.push_back(i%4+1);
        cout << *(max_element(ans.begin(), ans.end())) << '\n';
        for (auto& x : ans) cout << x << " ";
        cout << '\n';
    }
}

signed main() {
    ios_base::sync_with_stdio(0); 
    cin.tie(0); cout.tie(0);

    int t = 1;
    if (MULTI_TEST) cin >> t;
    while (t--) solve();

    return 0;
}
