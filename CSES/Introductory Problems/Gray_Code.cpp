#include <bits/stdc++.h>
using namespace std;

void printB(int n, int dig) {
    if (!dig) return;
    printB(n>>1, dig-1);
    cout << (n&1);
}

int main() {
    int n; cin >> n;
    for (int i = 0; i < (1 << n); ++i) printB(i ^ (i >> 1), n), cout << endl;
    return 0;
}