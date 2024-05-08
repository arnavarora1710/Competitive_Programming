// https://codeforces.com/contest/1691/problem/C
#pragma GCC optimize("Ofast")
#pragma GCC optimization("unroll-loops")

#include <bits/stdc++.h>
using namespace std;

#define int long long
typedef pair<int, int> pi;
#define f first
#define s second
#define MULTI_TEST (1)
const int maxn = 2e5 + 5, inf = 1e18;
int n, k; string s;

int calc() {
    int ans = 0;
    for (int i = 0; i + 1 < s.size(); ++i) {
        string tmp;
        tmp += s[i];
        tmp += s[i + 1];
        ans += stoi(tmp);
    }
    return ans;
}

void solve() {
    cin >> n >> k >> s;
    vector<int> ind;
    for (int i = 0; i < n; ++i)
        if (s[i] == '1') 
            ind.push_back(i);
    if (ind.size() == 1) {
        int val1 = ind[0];
        int val2 = n - ind[0] - 1;
        if (k - val2 >= 0) {
            swap(s[ind[0]], s[n - 1]);
        } else if (k - val1 >= 0) {
            swap(s[ind[0]], s[0]);
        }
    } else if (ind.size() > 1) {
        int val1 = ind[0];
        int val2 = n - ind[ind.size() - 1] - 1;
        if (k - val2 >= 0) {
            swap(s[ind[ind.size() - 1]], s[n - 1]);
            k -= val2;
        }
        if (k - val1 >= 0) {
            swap(s[ind[0]], s[0]);
            k -= val1;
        }
    }
    cout << calc() << endl;
}

signed main() {
    ios_base::sync_with_stdio(0); 
    cin.tie(0); cout.tie(0);

    int t = 1;
    if (MULTI_TEST) cin >> t;
    while (t--) solve();

    return 0;
}