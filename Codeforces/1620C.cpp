#include <bits/stdc++.h>
using namespace std;

#define int long long
int n, k, x;
string a;

void solve() {
    cin >> n >> k >> x >> a;
    reverse(a.begin(), a.end());
    string ans; x--;
    for (int i = 0; i < n; ++i) {
        if (a[i] == 'a') ans.push_back('a');
        else {
            int adj = 0;
            while (i < n && a[i] == '*') i++, adj++;
            int cur = adj * k + 1;
            string tmp(x % cur, 'b');
            ans += tmp;
            x /= cur;
            --i;
        }
    }
    reverse(ans.begin(), ans.end());
    cout << ans << endl;
}

signed main() {
    int t; cin >> t;
    while (t--) solve();
}
// n, k <= 2000 => O(n * k) is possible
// a**a, k = 1
// aa, aba, abba
// 1st lexicographically smallest string is trivially just the original string - *'s
// can't discard the 'a's because:
// **a* is diff from *** (placing all b's case)
// we can place [0, adjacent asterisks * k]
// but length is also a factor
// I can place k1 here, k2 here, ... so on for adjacent groups
// **a*** , k = 3 , x = 20
// 1.  a
// 2.  ab
// 3.  abb
// 4.  abbb
// 5.  abbbb
// 6.  abbbbb
// 7.  abbbbbb
// 8.  abbbbbbb
// 9.  abbbbbbbb
// 10. abbbbbbbbb
// 11. ba
// 12. bab
// 13. babb
// 14. babbb
// 15. babbbb
// 16. babbbbb
// 17. babbbbbb
// 18. babbbbbbb
// 19. babbbbbbbb
// 20. babbbbbbbbb
