// https://codeforces.com/problemset/problem/1555/D
#include <bits/stdc++.h>
using namespace std;
int n, m, l, r; string s;

int main() {
    cin >> n >> m >> s;
    string t = "abc";
    vector<vector<int>> prefix(6, vector<int>(n + 1));
    int curr = 0;
    do {
        for (int i = 0; i < n; ++i) prefix[curr][i + 1] += prefix[curr][i] + (s[i] != t[i % 3]);
        curr++;
    } while (next_permutation(t.begin(), t.end()));
    
    for (int q = 0; q < m; ++q) {
        cin >> l >> r;
        int ans = n;
        for (int i = 0; i < 6; ++i) 
            ans = min(ans, prefix[i][r] - prefix[i][l - 1]);
        cout << ans << endl;
    }
    return 0;
}