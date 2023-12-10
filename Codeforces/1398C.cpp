// https://codeforces.com/problemset/problem/1398/C
#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1e5 + 1;
int t, n; long long pre[MAXN]; string a; map<int, int> m;

int main() {
    cin >> t;
    while (t--) {
        cin >> n >> a; memset(pre, 0, sizeof(pre)); m.clear(); 
        long long ans = 0; m[0] = 1;
        for (int i = 1; i <= n; ++i) pre[i] = pre[i - 1] + a[i - 1] - '0';
        for (int i = 1; i <= n; ++i) ans += m[pre[i] - i], m[pre[i] - i]++;
        cout << ans << endl;
    }
    return 0;
}