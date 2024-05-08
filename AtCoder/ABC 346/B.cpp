#pragma GCC optimize("Ofast")
#pragma GCC optimization("unroll-loops")

#include <bits/stdc++.h>
using namespace std;

#define int long long
typedef pair<int, int> pi;
#define f first
#define s second
#define MULTI_TEST (0)
int W, B;

void solve() {
    cin >> W >> B;
    int N = W + B;
    string s = "wbwbwwbwbwbw";
    string tmp = s;
    while (s.size() <= 10000) s += tmp;
    for (int i = 0; i + N < s.size(); ++i) {
        int w = 0, b = 0;
        for (int j = i; j < i + N; ++j) {
            w += (s[j] == 'w');
            b += (s[j] == 'b');
        }
        if (w == W && b == B) {
            cout << "Yes";
            return;
        }
    }
    cout << "No";
}

signed main() {
    ios_base::sync_with_stdio(0); 
    cin.tie(0); cout.tie(0);

    int t = 1;
    if (MULTI_TEST) cin >> t;
    while (t--) solve();

    return 0;
}