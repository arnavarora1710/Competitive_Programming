#include <bits/stdc++.h>
using namespace std;
int t, n; vector<int> divisors(1000005);
 
signed main() {
    cin >> t;
    for (int i = 1; i < 1000005; ++i)
        for (int j = i; j < 1000005; j += i) 
            divisors[j]++;
    while (t--) {
        cin >> n; 
        cout << divisors[n] << endl;
    }
    return 0;
}