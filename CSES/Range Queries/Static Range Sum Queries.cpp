#include <bits/stdc++.h>
using namespace std;
const int MAXN = 2e5;
long long n, q, l, r, a[MAXN];

int main() {
    cin >> n >> q; 
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        if (i) a[i] += a[i - 1];
    }
    while (q--) {
        cin >> l >> r; l--; r--;
        cout << a[r] - (l ? a[l - 1] : 0) << endl;
    }

    return 0;
}