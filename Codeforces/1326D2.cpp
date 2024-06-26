// https://codeforces.com/contest/1326/problem/D2
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")

#include <bits/stdc++.h>
using namespace std;

#define int long long

typedef pair<int, int> pi;
#define f first
#define s second
#define MULTI_TEST (1)
const int maxn = 2e6 + 5, inf = 1e18;
int n, c, pref[maxn];
string s;

string solve_palindrome(const string& s)
{
    string a = s;
    reverse(a.begin(), a.end());
    a = s + "#" + a;
    c = 0;
    for (int i = 1; i < (int)a.size(); i++)
    {
        while (c != 0 && a[c] != a[i])
            c = pref[c - 1];
        if (a[c] == a[i])
            c++;
        pref[i] = c;
    }
    return s.substr(0, c);
}

void solve() {
    cin >> s;
    n = s.size();
    int i = 0, j = n - 1;
    while (i <= j && s[i] == s[j]) i++, j--;
    if (i > j) {
        cout << s << '\n';
        return;
    }
    string t = s.substr(i, j - i + 1);
    string t1 = solve_palindrome(t);
    reverse(t.begin(), t.end());
    string t2 = solve_palindrome(t);
    for (int k = 0; k < i; ++k) cout << s[k];
    if (t1.size() > t2.size()) cout << t1;
    else cout << t2;
    for (int k = j + 1; k < n; ++k) cout << s[k];
    cout << '\n';
}

signed main () {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t = 1;
    if (MULTI_TEST) cin >> t;
    while (t--) solve();

    return 0;
}
