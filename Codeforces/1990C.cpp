// https://codeforces.com/contest/1990/problem/C
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
int n, a[maxn];

void solve() {
    cin >> n;
    for (int i = 0; i < n; ++i) cin >> a[i];
    map<int, int> cnt, vis;
    vector<int> arr(n);
    int ans = 0;
    for (int i = 0; i < n; ++i) {
        if (!vis[a[i]]) {
            vis[a[i]] = true;
        } else {
            cnt[a[i]]++;
        }
        arr[i] = (cnt.empty() ? 0 : cnt.rbegin()->f);
        ans += a[i] + arr[i];
    }
    int p = 0;
    for (int i = 0; i < n; ++i) {
        if (!arr[i]) continue;
        int j = i + 1, ct = 1;
        while (j < n && arr[i] == arr[j]) j++, ct++;
        arr[i] = p;
        p = arr[j - 1];
        i = j - 1;
    }
    int sum = 0;
    for (int& i : arr)
        sum += i;
    for (int i = n - 1; i >= 0; --i) {
        ans += sum;
        sum -= arr[i];
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