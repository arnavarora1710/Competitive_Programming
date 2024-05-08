// https://codeforces.com/problemset/problem/1931/E
#pragma GCC optimize("Ofast")
#pragma GCC optimization("unroll-loops")

#include <bits/stdc++.h>
using namespace std;

#define int long long
typedef pair<int, int> pi;
#define f first
#define s second
#define MULTI_TEST (1)
int n, m, a[200005];

int countLeading(int nn) {
    int cnt = 0;
    while (nn) {
        if (nn%10 == 0) cnt++;
        else return cnt;
        nn /= 10;
    }
    return 0;
}

int countDigits(int nn) {
    int cnt = 0;
    while (nn) {
        cnt++;
        nn /= 10;
    }
    return cnt;
}

class Compare {
    public:
        bool operator()(int x, int y) {
            return countLeading(x) > countLeading(y);
        }
};

void solve() {
    cin >> n >> m;
    for (int i = 0; i < n; ++i) cin >> a[i];
    sort(a, a + n, Compare());
    int ans = 0;
    for (int i = 0; i < n; ++i) {
        if (!(i&1)) {
            int val = countDigits(a[i]) - countLeading(a[i]);
            ans += val;
        } else {
            int val = countDigits(a[i]);
            ans += val;
        }
    }
    if (ans > m) cout << "Sasha\n";
    else cout << "Anna\n";
}

signed main() {
    ios_base::sync_with_stdio(0); 
    cin.tie(0); cout.tie(0);

    int t = 1;
    if (MULTI_TEST) cin >> t;
    while (t--) solve();

    return 0;
}