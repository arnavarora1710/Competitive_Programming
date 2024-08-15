#include <iostream>

int main() {
    int N, T, A; std::cin >> N >> T >> A;
    int mn = std::min(T, A);
    int mx = std::max(T, A);
    int left = N - T - A;
    mn += left;
    std::cout << (mn > mx ? "No" : "Yes");
}