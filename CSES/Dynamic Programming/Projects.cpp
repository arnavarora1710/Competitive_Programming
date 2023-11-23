#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAXN = 2e5;
vector<vector<ll>> a; vector<pair<ll, ll>> dp(MAXN); vector<ll> mx(MAXN);
 
bool cmp(vector<ll>& f, vector<ll>& s) {return f[1] < s[1];}
 
int main() {
    int n; cin >> n; a.resize(n); 
    for (int i = 0; i < n; ++i) a[i].resize(3), cin >> a[i][0] >> a[i][1] >> a[i][2];
    sort(a.begin(), a.end(), cmp);
    
    dp[0] = {a[0][1], a[0][2]}; mx[0] = a[0][2];
    for (int i = 1; i < n; ++i) {
        int idx = lower_bound(dp.begin(), dp.begin() + i, make_pair(a[i][0], LLONG_MIN)) - dp.begin();
        dp[i] = {a[i][1], (idx ? mx[idx - 1] : 0) + a[i][2]};
        mx[i] = max(mx[i - 1], dp[i].second);
    }
    cout << mx[n - 1];

    return 0;
}