#pragma GCC optimize("Ofast")
#pragma GCC optimization("unroll-loops")

#include <bits/stdc++.h>
using namespace std;

#define double long double
#define int long long
typedef pair<int, int> pi;
#define f first
#define s second
#define mp make_pair
#define MULTI_TEST (0)
const int maxn = 2e5 + 5, inf = 1e18;
const double EPS = 1e-9;
int n, k, a[maxn];
string s;

bool cmp(pair<double, pi> x, pair<double, pi> y) {
    if (abs(x.f - y.f) < EPS) return x.s.s > y.s.s;
    else return x.f < y.f;
}

void solve() {
    cin >> n >> k >> s;
    for (int i = 0; i < n; ++i) cin >> a[i];
    vector<pair<int, char>> b;
    for (int i = 0; i < n; ++i) b.push_back({a[i], s[i]});
    sort(b.begin(), b.end());
    string t;
    for (int i = 0; i < n; ++i) t.push_back(b[i].s);
    sort(a, a + n);
    vector<double> fin(n);
    for (int i = 0; i < n; ++i) fin[i] = a[i] + (t[i] == '1' ? k + 0.1 : -k-0.1);
    int ans = 0;
    vector<pair<double, pi>> A;
    for (int i = 0; i < n; ++i) {
        if (fin[i] < a[i]) {
            A.push_back({fin[i], {i, 2}});
            A.push_back({a[i], {i, -2}});
        } else {
            A.push_back({a[i], {i, 1}});
            A.push_back({fin[i], {i, -1}});
        }
    }
    sort(A.begin(), A.end(), cmp);
    // for (auto v : A) 
    //     cerr << fixed << setprecision(15) << v.f << ' ' << v.s.f << ' ' << v.s.s << '\n';
    // cerr << '\n';
    set<pair<double, pi>> S;
    for (int i = 0; i < A.size(); ++i) {
        if (A[i].s.s == -1) S.erase({a[A[i].s.f], {A[i].s.f, 1}});
        else if (A[i].s.s == -2) {
            // cerr << "For " << A[i].s.f << '\n';
            // for (auto x : S) cerr << x.f << ' ';
            // cerr << '\n';
            ans += S.size();
        }
        else if (A[i].s.s == 1) S.insert(A[i]);
        else { 
            // cerr << "For " << A[i].s.f << '\n';
            // for (auto x : S) cerr << x.f << ' ';
            // cerr << '\n';
            ans += S.size();
        }
    }
    cout << ans;
}

signed main() {
    ios_base::sync_with_stdio(0); 
    cin.tie(0); cout.tie(0);

    int t = 1;
    if (MULTI_TEST) cin >> t;
    while (t--) solve();

    return 0;
}
