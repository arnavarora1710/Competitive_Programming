#include <iostream>

int main() {
    int N; std::cin >> N;
    if (N > 0) std::cout << (N * N + N) / 2;
    else std::cout << (2 - N * N + N) / 2;
}