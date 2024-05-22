#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n; cin >> n;
    if (!n) cout << 10;
    else if (n == 1) cout << 1;
    else {
        vector<int> ans(10);
        for (int i = 9; i >= 2; --i) {
            while (n % i == 0) {
                ans[i]++;
                n /= i;
            }
        }
        if (n != 1) cout << -1;
        else
            for (int i = 2; i <= 9; ++i)
                for (int j = 0; j < ans[i]; ++j) cout << i;
    }
}

int main () {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    solve();
}
