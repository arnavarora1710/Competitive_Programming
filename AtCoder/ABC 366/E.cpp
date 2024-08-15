#include <iostream>
#include <vector>
#include <algorithm>

#define int long long
int N, D;

void calc(std::vector<int>& A, std::vector<int>& Pa, std::vector<int>& DPa) {
    for (int i = -2000000; i <= 2000000; ++i) {
        int index = std::lower_bound(A.begin() + 1, A.end(), i) - A.begin();
        int pref = Pa[index - 1];
        int suff = Pa[N] - pref;
        int dist = (index - 1) * i - pref + suff - (N - index + 1) * i;
        if (dist <= D) DPa[dist]++;
    }
}

signed main() {
    std::cin >> N >> D;
    std::vector<int> X(N + 1), Y(N + 1), Px(N + 1), Py(N + 1);
    std::vector<int> DPx(D + 1), DPy(D + 1);
    for (int i = 1; i <= N; ++i)
        std::cin >> X[i] >> Y[i];
    std::sort(X.begin() + 1, X.end());
    std::sort(Y.begin() + 1, Y.end());
    for (int i = 1; i <= N; ++i)
        Px[i] = Px[i - 1] + X[i], Py[i] = Py[i - 1] + Y[i];
    calc(X, Px, DPx);
    calc(Y, Py, DPy);
    for (int i = 1; i <= D; ++i)
        DPy[i] += DPy[i - 1];
    int ans = 0;
    for (int i = 0; i <= D; ++i)
        ans += DPx[i] * DPy[D - i];
    std::cout << ans << '\n';
}