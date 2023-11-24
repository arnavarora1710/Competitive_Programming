#include <bits/stdc++.h>
using namespace std;
#define YES cout << "YES\n";
#define NO cout << "NO\n";
int t, a, b;

int main() {
    cin >> t;
    while (t--) {
        cin >> a >> b;
        if (2 * a - b < 0 || 2 * b - a < 0) NO
        else if ((2 * a - b) % 3 == 0 && (2 * b - a) % 3 == 0) YES
        else NO
    }
    return 0;
}

// alternative solution :
// a - k1 - 2k2 = 0, b - 2k1 - k2 = 0
// a + b = 3k1 + 3k2, a - b = k2 - k1
// a = k1 + 2k2, b = 2k1 + k2
// if ((a + b) % 3) NO
// else {
//     int k2 = a - (a + b) / 3, k1 = b - (a + b) / 3;
//     if (k1 >= 0 && k2 >= 0 && a - k1 - 2 * k2 == 0 && b - 2 * k1 - k2 == 0) YES
//     else NO
// }