#include <iostream>

int main() {
    int N, M; std::cin >> N >> M;
    std::cout << (M&1 || !(N&1) ? "yes" : "no");
}