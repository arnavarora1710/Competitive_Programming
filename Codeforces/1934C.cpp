// https://codeforces.com/contest/1934/problem/C
#pragma GCC optimize("Ofast")
#pragma GCC optimization("unroll-loops")

#include <bits/stdc++.h>
using namespace std;

#define int long long
#define MULTI_TEST (1)
int n, m, d;

int ask(int x, int y) {
    printf("? %lld %lld\n", x, y);
    fflush(stdout);
    scanf("%lld", &d);
    return d;
}

void solve() {
    scanf("%lld %lld", &n, &m);

    int q1 = ask(1, 1);
    int q2, q3, q4;
    if (q1 + 1 <= n) q2 = ask(q1 + 1, 1);
    else q2 = ask(n, q1 - n + 2);
    if (q1 + 1 <= n) q3 = ask(1, q1 + 1);
    else {
        int xx;
        if (n - 1 < m - (q1 - n + 2)) xx = n - 1;
        else xx = m - (q1 - n + 2);
        q3 = ask(n - xx, q1 - n + 2 + xx);
    }
    if (q1 + 1 <= n) q4 = ask(q1 + 1 - q2/2, 1 + q2/2);
    else q4 = ask(n - q2/2, q1 - n + 2 + q2/2);
    
    if (q4 == 0) {
        if (q1 + 1 <= n)
            printf("! %lld %lld\n", q1 + 1 - q2/2, 1 + q2/2);
        else 
            printf("! %lld %lld\n", n - q2/2, q1 - n + 2 + q2/2); 
    }
    else {
        if (q1 + 1 <= n)
            printf("! %lld %lld\n", q1 + 1 - q3/2, 1 + q3/2);
        else {
            int xx;
            if (n - 1 < m - (q1 - n + 2)) xx = n - 1;
            else xx = m - (q1 - n + 2);
            printf("! %lld %lld\n", n - xx - q3/2, q1 - n + 2 + xx + q3/2); 
        }
    }
    fflush(stdout);
}

signed main() {
    int t = 1;
    if (MULTI_TEST) scanf("%lld", &t);
    while (t--) solve();

    return 0;
}