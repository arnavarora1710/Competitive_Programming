// https://codeforces.com/contest/1937/problem/C
#pragma GCC optimize("Ofast")
#pragma GCC optimization("unroll-loops")

#include <bits/stdc++.h>
using namespace std;

#define int long long
#define MULTI_TEST (1)
int n;
char qq;

int ask(int i, int j, int k, int l) {
    cout << "? " << i << " " << j << " " << k << " " << l << endl;
    cin >> qq;
    if (qq == '>') return 1;
    else if (qq == '=') return 0;
    else return -1;
}

void solve() {
    cin >> n;
    int idx = 0;
    for (int i = 1; i < n; ++i) {
        int res = ask(i, i, idx, idx);
        if (res == 1) {
            idx = i;
        }
    }

    int num_idx = 0;
    for (int i = 1; i < n; ++i) {
        int res = ask(idx, i, idx, num_idx);
        if (res == 1) {
            num_idx = i;
        } else if (res == 0) {
            res = ask(num_idx, num_idx, i, i);
            if (res == 1) {
                num_idx = i;
            }
        }
    }

    cout << "! " << idx << " " << num_idx << endl;
}

signed main() {
    ios_base::sync_with_stdio(0); 
    cin.tie(0); cout.tie(0);

    int t = 1;
    if (MULTI_TEST) cin >> t;
    while (t--) solve();

    return 0;
}