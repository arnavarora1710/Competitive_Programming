// https://codeforces.com/contest/1896/problem/A
#include <bits/stdc++.h>
using namespace std;
const int MAXN = 10;
int t, n, a[MAXN];

int main() {
    cin >> t;
    while (t--) {
        cin >> n; for (int i = 0; i < n; ++i) cin >> a[i];
        cout << (a[0] == 1 ? "YES" : "NO") << endl;
    }
    return 0;
}