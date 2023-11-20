#include <bits/stdc++.h>
using namespace std;
int n;

int main() {
    cin >> n; 
    if (n == 2 || n == 3) cout << "NO SOLUTION";
    else {
        int hi = n, lo = n - (n >> 1);
        for (int i = 0; i < n; ++i) {
            if (i&1) cout << hi-- << " ";
            else cout << lo-- << " ";
        }
    }
    return 0;
}