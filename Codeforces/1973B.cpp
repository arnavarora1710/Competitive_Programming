// https://codeforces.com/contest/1973/problem/B
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
const int maxn = 2e5 + 5, inf = 1e18, bitscount = 25;
int n, a[maxn];
int prefix_count[bitscount][maxn];
 
// Function to find the prefix sum
void findPrefixCount()
{
 
    // Loop for each bit
    for (int i = 0; i < bitscount; i++) {
        // Loop to find prefix count
        prefix_count[i][0] = ((a[0] >> i) & 1);
        for (int j = 1; j < n; j++) {
            prefix_count[i][j] = ((a[j] >> i) & 1);
            prefix_count[i][j] += prefix_count[i][j - 1];
        }
    }
}
 
// Function to answer query
int rangeOr(int l, int r)
{
 
    // To store the answer
    int ans = 0;
 
    // Loop for each bit
    for (int i = 0; i < bitscount; i++) {
        // To store the number of variables
        // with ith bit set
        int x;
        if (l == 0)
            x = prefix_count[i][r];
        else
            x = prefix_count[i][r]
                - prefix_count[i][l - 1];
 
        // Condition for ith bit
        // of answer to be set
        if (x != 0)
            ans = (ans | (1 << i));
    }
 
    return ans;
}

bool check(int m) {
    int p = 0;
    set<int> ans;
    // cerr << m << ":\n";
    for (int i = m - 1; i < n; ++i, ++p) {
        // cerr << p << ' ' << i << ' ' << rangeOr(p, i) << '\n';
        ans.insert(rangeOr(p, i));
    }
    // cerr << '\n';
    return ans.size() == 1;
}

void solve() {
    cin >> n; for (int i = 0; i < n; ++i) cin >> a[i];
    findPrefixCount();
    int l = 0, r = n;
    while (r - l > 1) {
        int m = l + (r - l) / 2;
        if (!check(m)) l = m;
        else r = m;
    }
    cout << r << '\n';
}

signed main() {
    ios_base::sync_with_stdio(0); 
    cin.tie(0); cout.tie(0);

    int t = 1;
    if (MULTI_TEST) cin >> t;
    while (t--) solve();

    return 0;
}
