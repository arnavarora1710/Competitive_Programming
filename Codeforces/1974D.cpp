// https://codeforces.com/contest/1974/problem/D
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
int n;
string s, ans;
map<char, vector<int>> ind;

bool fun(char x, char y, bool turn) {
    int i = 0, j = 0;
    int sz1 = ind[x].size(), sz2 = ind[y].size();
    while (i < sz1 && j < sz2) {
        char t = (turn ? 'R' : 'H');
        ans[ind[x][i++]] = ans[ind[y][j++]] = t;
        turn = !turn;
    }
    int left1 = sz1 - i, left2 = sz2 - j;
    if (left1&1 || left2&1) {
        cout << "NO\n";
        return 0;
    }
    turn = 1;
    while (i < sz1) {
        if (turn) ans[ind[x][i]] = 'R';
        else ans[ind[x][i]] = 'H';
        turn = !turn;
        i++;
    }
    turn = 1;
    while (j < sz2) {
        if (turn) ans[ind[y][j]] = 'R';
        else ans[ind[y][j]] = 'H';
        turn = !turn;
        j++;
    }
    return 1;
}

void solve() {
    cin >> n >> s;
    ans.resize(n); ind.clear();
    for (int i = 0; i < n; ++i) ind[s[i]].push_back(i);
    if (!fun('N', 'S', 1)) return;
    if (!fun('W', 'E', 0)) return;
    if (ans.find('H') == string::npos || ans.find('R') == string::npos) cout << "NO\n";
    else cout << ans << '\n';
}

signed main() {
    ios_base::sync_with_stdio(0); 
    cin.tie(0); cout.tie(0);

    int t = 1;
    if (MULTI_TEST) cin >> t;
    while (t--) solve();

    return 0;
}
