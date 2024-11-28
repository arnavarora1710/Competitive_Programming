#include <bits/stdc++.h>
using namespace std;

int main() {
    int i = 2;
    while (true) {
        int cnt = 0;
        for (int j = 1; j <= i; ++j) {
            if (gcd(i, j) == 1) {
                cnt++;
            }
        }
        if (cnt == 40) {
            cout << i;
            break;
        }
        i++;
    }
}