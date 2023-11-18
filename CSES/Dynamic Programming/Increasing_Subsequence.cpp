#include <bits/stdc++.h>
using namespace std;
const int MAXN = 2e5 + 1;
int a[MAXN];

int main() {
    int n; cin >> n; for (int i = 0; i < n; ++i) cin >> a[i];
    vector<int> res; res.push_back(a[0]);
    for (int i = 1; i < n; ++i) {
        if (a[i] > res.back()) res.push_back(a[i]);
        else {
            int idx = lower_bound(res.begin(), res.end(), a[i]) - res.begin();
            res[idx] = a[i];
        }
    }
    cout << res.size();
    return 0;
}