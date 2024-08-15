#include <iostream>
#include <vector>
#include <string>

int main() {
    int N; std::cin >> N;
    int mx = 0;
    std::vector<std::string> A(N);
    for (auto& s : A) {
        std::cin >> s;
        mx = std::max(mx, (int) s.size());
    }
    std::vector<std::string> B(mx);
    for (int i = 0; i < mx; ++i)
        for (int j = 0; j < N; ++j) 
            B[i] += '*';
    for (int i = N - 1; i >= 0; --i)
        for (int j = 0; j < A[i].size(); ++j)
            B[j][N - i - 1] = A[i][j];
    for (int i = 0; i < mx; ++i) {
        while (B[i].back() == '*') 
            B[i].pop_back();
        std::cout << B[i] << '\n';
    }
}