#include <iostream>

int A[105][105][105];

int main() {
    int N; std::cin >> N;
    for (int i = 1; i <= N; ++i)
        for (int j = 1; j <= N; ++j)
            for (int k = 1; k <= N; ++k)
                std::cin >> A[i][j][k];
    for (int i = 1; i <= N; ++i)
        for (int j = 1; j <= N; ++j)
            for (int k = 1; k <= N; ++k)
                A[i][j][k] += A[i - 1][j][k] + A[i][j - 1][k] + A[i][j][k - 1] 
                            - A[i - 1][j - 1][k] - A[i - 1][j][k - 1]
                            - A[i][j - 1][k - 1] + A[i - 1][j - 1][k - 1];
    int Q; std::cin >> Q;
    while (Q--) {
        int Lx, Rx, Ly, Ry, Lz, Rz;
        std::cin >> Lx >> Rx >> Ly >> Ry >> Lz >> Rz;
        std::cout << A[Rx][Ry][Rz] - A[Lx - 1][Ry][Rz] - A[Rx][Ly - 1][Rz] 
                    - A[Rx][Ry][Lz - 1] + A[Lx - 1][Ly - 1][Rz]
                    + A[Lx - 1][Ry][Lz - 1] + A[Rx][Ly - 1][Lz - 1] 
                    - A[Lx - 1][Ly - 1][Lz - 1] << '\n';
    }
}