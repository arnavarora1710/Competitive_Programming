// Author: Arnav Arora
// It is ok to share my code anonymously for educational purposes

#include <bits/stdc++.h>
using namespace std;

int main() {
    // n may turn into a large number so use longs
    long n; 
    
    // take in input
    cin >> n; 

    // print out the initial value
    cout << n << " ";

    // simulate the process as described in the problem
    while (n != 1) {
        // if n is odd, multiply it by 3 and add 1
        // if n is even, divide by 2
        // bit hack notes:
        // 1) (right shifting a number by 1 is equivalent to division by 2)
        // 2) (to check if a number is odd, check if its first bit is set)
        if (n&1) n = 3 * n + 1;
        else n >>= 1;

        // print out the current value
        cout << n << " ";
    }
    return 0;
}