// https://codeforces.com/contest/1883/problem/D
#pragma GCC optimize("Ofast")
#pragma GCC optimization("unroll-loops")

#include <bits/stdc++.h>
using namespace std;

#define int long long
#define f first
#define s second
typedef pair<int, int> pi;
#define MULTI_TEST (0)
int n, l, r;
char ch;
multiset<pi> s;

struct cmp {
    bool operator()(const pi& x, const pi& y) const {
        if (x.s == y.s) return x.f < y.f;
        else return x.s < y.s;
    }
};

multiset<pi, cmp> s1;

bool intersect(pi x, pi y) {
    int lx = x.f, rx = x.s;
    int ly = y.f, ry = y.s;
    return (ly <= rx && ry >= rx);
}

void solve() {
    cin >> n;
    while (n--) {
        cin >> ch >> l >> r;
        if (ch == '+') {
            s.insert({l, r});
            s1.insert({l, r});
        }
        else {
            s.erase(s.find({l, r}));
            s1.erase(s1.find({l, r}));
        }
        if (s.empty()) cout << "NO\n";
        else {
            pi x = *s1.begin(), y = *s.rbegin();
            if (intersect(x, y)) cout << "NO\n";
            else cout << "YES\n";
        }
    }    
}

signed main() {
    ios_base::sync_with_stdio(0); 
    cin.tie(0); cout.tie(0);

    int t = 1;
    if (MULTI_TEST) cin >> t;
    while (t--) solve();

    return 0;
}