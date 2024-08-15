#include <iostream>
#include <map>

int main() {
    int N; std::cin >> N;
    std::map<int, int> M;
    while (N--) {
        int Q; std::cin >> Q;
        if (Q == 1) {
            int X; std::cin >> X;
            M[X]++;
        } else if (Q == 2) {
            int X; std::cin >> X;
            M[X]--;
            if (!M[X]) M.erase(X);
        } else {
            std::cout << M.size() << '\n';
        }
    }
}