#include <bits/stdc++.h>
using namespace std;
#define print(a) for (auto& x : a) cout << x << " "
const int MAXN = 1e6 + 1;
bool vis[MAXN]; vector<int> a, b;

int main() {
    int n; cin >> n; long long sum = (1LL * n * (n + 1)) / 2;
    if (sum&1) cout << "NO";
    else {
        long long target = sum / 2; int start = n;
        while (target > n || vis[target]) target -= start, vis[start--] = true;
        vis[target] = true;
        for (int i = 1; i <= n; ++i) vis[i] ? a.push_back(i) : b.push_back(i);
        cout << "YES\n" << a.size() << endl; print(a);
        cout << endl << b.size() << endl; print(b);
    }
    return 0;
}