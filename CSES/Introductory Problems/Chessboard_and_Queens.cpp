#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
#pragma GCC optimization("unroll-loops")

#include <bits/stdc++.h>
using namespace std;

#define int long long
#define MULTI_TEST (0)
int ans;

bool valid(int i, int j) {
    return i >= 0 && j >= 0 && i < 8 && j < 8;
}

bool check(vector<vector<char>> grid) {
    for (int i = 0; i < 8; ++i) {
        for (int j = 0; j < 8; ++j) {
            if (grid[i][j] == 'Q') {
                for (int k = 0; k < 8; ++k) {
                    if (k != i && grid[k][j] == 'Q') return false;
                    if (k != j && grid[i][k] == 'Q') return false;
                }
                for (int k = 1; k < 8; ++k) {
                    if (valid(i + k, j - k) && grid[i + k][j - k] == 'Q') return false; 
                    if (valid(i - k, j - k) && grid[i - k][j - k] == 'Q') return false; 
                    if (valid(i + k, j + k) && grid[i + k][j + k] == 'Q') return false; 
                    if (valid(i - k, j + k) && grid[i - k][j + k] == 'Q') return false; 
                }
            }
        }
    }
    return true;
}


void backtrack(vector<vector<char>> grid, int j) {
    if (!check(grid)) return;
    if (j >= 8) {
        ans++; return;
    }
    for (int i = 0; i < 8; ++i) {
        if (grid[i][j] == '.') {
            grid[i][j] = 'Q';
            backtrack(grid, j + 1);
            grid[i][j] = '.';
        }
    }
}

void solve() {
    vector<vector<char>> grid(8, vector<char>(8));
    for (int i = 0; i < 8; ++i) for (int j = 0; j < 8; ++j) cin >> grid[i][j];
    backtrack(grid, 0);
    cout << ans << endl;
}

signed main() {
    ios_base::sync_with_stdio(0); 
    cin.tie(0); cout.tie(0);

    int t = 1;
    if (MULTI_TEST) cin >> t;
    while (t--) solve();

    return 0;
}