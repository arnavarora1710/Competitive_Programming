// https://codeforces.com/contest/1368/problem/B
#pragma GCC optimize("Ofast")
#pragma GCC optimization("unroll-loops")

#include <bits/stdc++.h>
using namespace std;

#define int long long
typedef pair<int, int> pi;
#define f first
#define s second
#define MULTI_TEST (0)
const int maxn = 2e5 + 5, inf = 1e18;
int n;
vector<int> mp;

int calc() {
    int prod = 1;
    for (auto& v : mp) prod *= v;
    return prod;
}

void solve() {
    cin >> n;
    string t = "codeforces";
    mp.resize(10);
    for (int i = 0; i < 10; ++i) mp[i] = 1;
    int prod = 1;
    while (prod < n) {
        for (int i = 0; i < 10; ++i) {
            mp[i]++;
            prod = calc();
            if (prod >= n) break;
        }
    }
    for (int i = 0; i < 10; ++i)
        for (int j = 0; j < mp[i]; ++j) cout << t[i];
    cout << '\n';
}

signed main() {
    ios_base::sync_with_stdio(0); 
    cin.tie(0); cout.tie(0);

    int t = 1;
    if (MULTI_TEST) cin >> t;
    while (t--) solve();

    return 0;
}
