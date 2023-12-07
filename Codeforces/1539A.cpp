// https://codeforces.com/contest/1539/problem/A
#include <bits/stdc++.h>
using namespace std;
long long k, n, x, t;

int main() {
    cin >> k;
    while (k--) {
        cin >> n >> x >> t;
        long long f = min(n-1, t/x);
        long long answer = f*(n-f);
        answer += ((f*(f-1))/2);
        cout << answer << endl;
    }
    return 0;
}