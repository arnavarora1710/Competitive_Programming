// https://codeforces.com/contest/1080/problem/C
#pragma GCC optimize("Ofast")
#pragma GCC optimization("unroll-loops")

#include <iostream>
using namespace std;

#define int long long
typedef pair<int, int> pi;
#define f first
#define s second
#define MULTI_TEST (1)
const int maxn = 2e5 + 5, inf = 1e18;
int n, m, x1, x2, x3, x4, y1, y2, y3, y4;

int pr(int x, int y) {
    return (((x + 1) / 2) * ((y + 1) / 2)) + ((x / 2) * (y / 2));
}

int white(int x, int y, int xx, int yy) {
    return pr(xx, yy) - pr(x - 1, yy) - pr(xx, y - 1) + pr(x - 1, y - 1);
}

int black(int x, int y, int xx, int yy) {
    return (xx - x + 1) * (yy - y + 1) - white(x, y, xx, yy);
}

void solve() {
    cin >> n >> m >> x1 >> y1 >> x2 >> y2 >> x3 >> y3 >> x4 >> y4;
    int w = white(1, 1, n, m);
    int b = black(1, 1, n, m);
    w += black(x1, y1, x2, y2);
    b -= black(x1, y1, x2, y2);
    w -= white(x3, y3, x4, y4);
    b += white(x3, y3, x4, y4);
    int x5 = max(x1, x3), x6 = min(x2, x4);
    int y5 = max(y1, y3), y6 = min(y2, y4);
    if (x5 <= x6 && y5 <= y6) {
        w -= black(x5, y5, x6, y6);
        b += black(x5, y5, x6, y6);
    }
    cout << w << " " << b << endl;
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int t = 1;
    if (MULTI_TEST) cin >> t;
    while (t--) solve();

    return 0;
}
