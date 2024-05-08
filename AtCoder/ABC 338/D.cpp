#include <iostream>
using namespace std;

const int maxn = 200005;
int n, m, a[maxn]; 
long long ans[maxn];

int main() {
    cin >> n >> m; for (int i = 0; i < m; ++i) cin >> a[i];

    // 0 = edge b/w 1 and 2
    // n - 1 = edge b/w n and 1
    for (int i = 0; i < m; ++i) a[i]--;

    for (int i = 0; i + 1 < m; ++i) {
        long long start = a[i], end = a[i + 1];
        if (end < start) swap(end, start);

        // if we take the straight path
        ans[start] += n + start - end;
        ans[end] -= n + start - end; 
        
        // if we take the other (circular) path
        ans[0] += end - start;
        ans[start] -= end - start;
        
        ans[end] += end - start;
        ans[n] -= end - start;
    } 

    for (int i = 1; i <= n; ++i) ans[i] += ans[i - 1];
    
    long long res = 1e18;
    for (int i = 0; i < n; ++i) res = min(res, ans[i]);

    cout << res;
}
