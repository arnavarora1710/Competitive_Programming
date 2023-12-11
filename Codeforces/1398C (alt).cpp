// https://codeforces.com/problemset/problem/1398/C
#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1e5;
int t, n, arr[MAXN], pre[MAXN]; string a; map<int, int> m;

int main() {
    cin >> t;
    while (t--) {
        cin >> n >> a; for (int i = 0; i < n; ++i) arr[i] = a[i] - '0' - 1;
        long long ans = 0; m.clear(); m[0] = 1;
        for (int i = 0; i < n; ++i) {
            pre[i] = (i - 1 >= 0 ? pre[i - 1] : 0) + arr[i];
            ans += m[pre[i]];
            m[pre[i]]++;
        }
        cout << ans << endl;
    }
    return 0;
}