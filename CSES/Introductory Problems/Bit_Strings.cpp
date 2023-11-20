#include <bits/stdc++.h>
using namespace std;
const int MOD = 1e9 + 7;

int power(int a, int b) {
    int res = 1;
    while (b) {
        if (b&1) res = (1LL * res * a) % MOD;
        a = (1LL * a * a) % MOD;
        b >>= 1;
    } 
    return res;
}

int main() {
    int n; cin >> n; cout << power(2, n);
    return 0;
}