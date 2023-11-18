#include <bits/stdc++.h>
using namespace std;
long n, x, sum;

int main() {
    cin >> n; for (int i = 0; i < n - 1; ++i) cin >> x, sum += x;
    cout << ((1LL * n * (n + 1)) >> 1) - sum;
    return 0;
}