// https://codeforces.com/contest/1904/problem/D1
#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1000;
int t, n, a[MAXN], b[MAXN];

int main() {
    cin >> t;
    while (t--) {
        cin >> n; bool flag = true;
        for (int i = 0; i < n; ++i) cin >> a[i];
        for (int i = 0; i < n; ++i) cin >> b[i];
        for (int i = 0; i < n; ++i) {
            int j = i, f = 0;
            while (j >= 0 && b[j] >= b[i] && a[j] < b[i]) j--;
            if (j >= 0 && a[j] == b[i]) f = 1;
            j = i;
            while (j < n && b[j] >= b[i] && a[j] < b[i]) j++;
            if (j < n && a[j] == b[i]) f = 1;
            if (!f) {
                flag = false; break;
            }
        }
        if (flag) cout << "YES\n";
        else cout << "NO\n";
    }
    return 0;
}