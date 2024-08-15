// https://codeforces.com/contest/2000/problem/D
#pragma GCC optimize("Ofast")
#pragma GCC optimization("unroll-loops")

#include <bits/stdc++.h>
using namespace std;

#define int long long
typedef pair<int, int> pi;
#define f first
#define s second
#define mp make_pair
#define MULTI_TEST (1)
const int maxn = 2e5 + 5, inf = 1e18;
int n, a[maxn], p[maxn];
string s;

void solve() {
    cin >> n;
    for (int i = 0; i < n; ++i) cin >> a[i];
    cin >> s;
    for (int i = 0; i < n; ++i)
        p[i] = (i ? p[i - 1] : 0) + a[i];
    map<char, vector<int>> mp;
    for (int i = 0; i < n; ++i) mp[s[i]].push_back(i);
    int N = mp['L'].size(), M = mp['R'].size();
    int i = 0, j = M - 1, ans = 0;
    while (i < N && j >= 0) {
        int ind1 = mp['L'][i], ind2 = mp['R'][j];
        if (ind1 < ind2) {
            ans += p[ind2] - (ind1 ? p[ind1 - 1] : 0);
            i++, j--;
        } else break;
    }
    cout << ans << '\n';
}

signed main() {
    ios_base::sync_with_stdio(0); 
    cin.tie(0); cout.tie(0);

    int t = 1;
    if (MULTI_TEST) cin >> t;
    while (t--) solve();

    return 0;
}
