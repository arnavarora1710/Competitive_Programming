// https://codeforces.com/problemset/problem/1907/C
#include <bits/stdc++.h>
using namespace std;
int t, n, freq[26]; string a;

int main() {
    cin >> t;
    while (t--) {
        cin >> n >> a; memset(freq, 0, sizeof(freq));
        for (int i = 0; i < n; ++i) freq[a[i] - 'a']++;
        int mx = 0; for (int i = 0; i < 26; ++i) mx = max(mx, freq[i]);
        cout << max(n&1, 2 * mx - n) << endl;
    }
    return 0;
}