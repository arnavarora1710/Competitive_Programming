// https://codeforces.com/contest/1742/problem/F
#pragma GCC optimize("Ofast")
#pragma GCC optimization("unroll-loops")

#include <bits/stdc++.h>
using namespace std;

#define int long long
typedef pair<int, int> pi;
#define f first
#define s second
#define MULTI_TEST (1)
const int maxn = 2e5 + 5, inf = 1e18;
int q, d, k, occ[26], occ1[26];
string x;

void submit(bool yes) { cout << (yes ? "YES" : "NO") << '\n'; }

// first op will always be YES if type 1
// NO if type 2
void solve() {
  cin >> q;
  int index1 = 1, index2 = 1;
  memset(occ, 0, sizeof(occ));
  memset(occ1, 0, sizeof(occ1));
  occ[0]++, occ1[0]++;
  while (q--) {
    cin >> d >> k >> x;
    if (d == 1) {
      for (int i = 0; i < x.size(); ++i)
        occ[x[i] - 'a'] += k;
    } else {
      for (int i = 0; i < x.size(); ++i)
        occ1[x[i] - 'a'] += k;
    }
    bool done = 0;
    for (int i = 0; i < 26; ++i) {
      if (occ[i] < occ1[i]) {
        submit(1);
        done = 1;
        break;
      } else if (occ[i] > occ1[i]) {
        submit(0);
        done = 1;
        break;
      }
    }
    if (!done)
      submit(0);
  }
}

signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  int t = 1;
  if (MULTI_TEST)
    cin >> t;
  while (t--)
    solve();

  return 0;
}
