#include <bits/stdc++.h>
using namespace std;

#define int long long

signed main() {
    vector<double> ans;
    int x;
    while (cin >> x)
        ans.push_back(sqrt(x));
    reverse(ans.begin(), ans.end());
    for (auto x : ans) 
        cout << fixed << setprecision(4) << x << '\n';
    return 0;
}
