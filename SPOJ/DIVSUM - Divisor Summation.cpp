#pragma GCC optimize("Ofast")
#pragma GCC optimization("unroll-loops")
 
#include <bits/stdc++.h>
using namespace std;
 
#define int long long
typedef pair<int, int> pi;
#define f first
#define s second
#define MULTI_TEST (1)
const int maxn = 500000, inf = 1e18;
int n;
 
void solve() {
    cin >> n;
    int sum = 0;
    for (int i = 1; i * i <= n; ++i) {
        if (n % i == 0) {
            if (i != n) sum += i;
            if (i != n / i && n / i != n) sum += n / i;
        }
    }
    cout << sum << endl; 
}
 
signed main() {
    ios_base::sync_with_stdio(0); 
    cin.tie(0); cout.tie(0);
 
    int t = 1;
    if (MULTI_TEST) cin >> t;
    while (t--) solve();
 
    return 0;
} 