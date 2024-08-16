// https://codeforces.com/contest/2004/problem/D
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
int n, q;
string a[maxn];

void fillPre(vector<int>& A, string col) {
    for (int i = 0; i < n; ++i) {
        if (a[i] == col) 
            A[i] = i;
        else if (i) 
            A[i] = A[i - 1];
        else 
            A[i] = -1;
    }
}

void fillSuf(vector<int>& A, string col) {
    for (int i = n - 1; i >= 0; --i) {
        if (a[i] == col)
            A[i] = i;
        else if (i + 1 < n) 
            A[i] = A[i + 1];
        else 
            A[i] = -1;
    }
}

void solve() {
    cin >> n >> q;
    for (int i = 0; i < n; ++i) {
        char x, y; cin >> x >> y;
        a[i].clear();
        a[i] += x; a[i] += y;
    }
    vector<int> Pbg(n), Pbr(n), Pby(n), Pgr(n), Pgy(n), Pry(n);
    vector<int> Sbg(n), Sbr(n), Sby(n), Sgr(n), Sgy(n), Sry(n);
    fillPre(Pbg, "BG");
    fillPre(Pbr, "BR");
    fillPre(Pby, "BY");
    fillPre(Pgr, "GR");
    fillPre(Pgy, "GY");
    fillPre(Pry, "RY");
    fillSuf(Sbg, "BG");
    fillSuf(Sbr, "BR");
    fillSuf(Sby, "BY");
    fillSuf(Sgr, "GR");
    fillSuf(Sgy, "GY");
    fillSuf(Sry, "RY");
    while (q--) {
        int x, y; cin >> x >> y;
        x--, y--;
        if (x > y) swap(x, y);
        if (a[x][0] == a[y][0] || a[x][0] == a[y][1] || a[x][1] == a[y][0] || a[x][1] == a[y][1]) {
            cout << y - x << '\n';
        } else {
            int ans = inf;
            string s = a[x], t = a[y];
            string olds = s, oldt = t;
            for (int i = 0; i < 2; ++i) {
                for (int j = 0; j < 2; ++j) {
                    swap(s[i], t[j]);
                    sort(s.begin(), s.end());
                    int ind1, ind2;
                    if (s == "BG") {
                        ind1 = Pbg[x];
                        ind2 = Sbg[x];
                    } else if (s == "BR") {
                        ind1 = Pbr[x];
                        ind2 = Sbr[x];
                    } else if (s == "BY") {
                        ind1 = Pby[x];
                        ind2 = Sby[x];
                    } else if (s == "GR") {
                        ind1 = Pgr[x];
                        ind2 = Sgr[x];
                    } else if (s == "GY") {
                        ind1 = Pgy[x];
                        ind2 = Sgy[x];
                    } else {
                        ind1 = Pry[x];
                        ind2 = Sry[x];
                    }
                    if (ind2 > x && ind2 < y) {
                        ans = min(ans, y - x);
                    } else {
                        int cost1 = (ind1 == -1 ? inf : x - ind1);
                        int cost2 = (ind2 == -1 ? inf : ind2 - y);
                        ans = min(ans, y - x + 2 * min(cost1, cost2));
                    }
                    s = olds, t = oldt;    
                }
            }
            cout << (ans == inf ? -1 : ans) << '\n';
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
