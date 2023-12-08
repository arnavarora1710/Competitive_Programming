#include <bits/stdc++.h>
using namespace std;
int n, m, a, b; set<int> dis;

class DSU {
    public:
        vector<int> id;
        DSU(int sz) {
            id.resize(sz + 1);
            for (int i = 1; i <= sz; ++i) id[i] = i;
        }
        int find(int u) {
            if (id[u] == u) return u;
            return id[u] = find(id[u]);
        }
        void unionThese(int u, int v) {
            int idU = find(u), idV = find(v);
            id[idU] = idV;
        }
};

int main() {
    cin >> n >> m; DSU uf = *(new DSU(n));
    for (int i = 0; i < m; ++i) {
        cin >> a >> b;
        uf.unionThese(a, b);
    }
    for (int i = 1; i <= n; ++i) {
        uf.find(i);
        dis.insert(uf.id[i]);
    }
    cout << dis.size() - 1 << endl;
    vector<int> ans(dis.begin(), dis.end());
    for (int i = 1; i < (int) ans.size(); ++i) cout << ans[i] << " " << ans[i - 1] << endl;
    return 0;
}