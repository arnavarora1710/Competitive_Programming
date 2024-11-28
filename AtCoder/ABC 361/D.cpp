#pragma GCC optimize("Ofast")
#pragma GCC optimization("unroll-loops")

#include <bits/stdc++.h>
using namespace std;

#define int long long
typedef pair<int, int> pi;
#define f first
#define s second
#define mp make_pair
#define MULTI_TEST (0)
const int maxn = 2e5 + 5, inf = 1e18;
int n; string s, t;

void solve() {
    cin >> n >> s >> t;
    s += "$$";
    t += "$$";
    map<string, int> dist;
    queue<string> q; q.push(s);
    dist[s] = 0;
    while (!q.empty()) {
        string state = q.front(); q.pop();
        int i = 0; while (state[i] != '$') i++;
        int tp = dist[state];
        for (int j = 0; j < n + 1; ++j) {
            if (state[j] == '$' || state[j + 1] == '$') continue;
            swap(state[j], state[i]);
            swap(state[j + 1], state[i + 1]);
            if (dist.find(state) == dist.end()) {
                q.push(state);
                dist[state] = tp + 1;
            }
            swap(state[j], state[i]);
            swap(state[j + 1], state[i + 1]);
        }
    }
    if (dist.find(t) == dist.end()) cout << -1 << '\n';
    else cout << dist[t];
}

signed main() {
    ios_base::sync_with_stdio(0); 
    cin.tie(0); cout.tie(0);

    int t = 1;
    if (MULTI_TEST) cin >> t;
    while (t--) solve();

    return 0;
}
