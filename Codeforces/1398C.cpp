// https://codeforces.com/problemset/problem/1398/C
#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1e5;
int t, n, pre[MAXN]; string a; map<int, int> m;

int main() {
    cin >> t;
    while (t--) {
        cin >> n >> a; memset(pre, 0, sizeof(pre)); m.clear(); 
        long long ans = 0; pre[0] = a[0] - '0'; m[0] = 1;
        for (int i = 1; i < n; ++i) pre[i] = pre[i - 1] + a[i] - '0';
        for (int i = 0; i < n; ++i) m[pre[i] - i - 1]++;
        for (auto& v : m) ans +=  1LL * v.second * (v.second - 1) / 2;
        cout << ans << endl;
    }
    return 0;
}