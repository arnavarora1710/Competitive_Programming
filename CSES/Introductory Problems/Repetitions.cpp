#include <bits/stdc++.h>
using namespace std;
string a;

int main() {
    cin >> a; int ans = 0, count = 1;
    for (int i = 1; i < a.size(); ++i) {
        if (a[i] == a[i - 1]) count++;
        else ans = max(ans, count), count = 1;
    }
    cout << max(ans, count);
    return 0;
}