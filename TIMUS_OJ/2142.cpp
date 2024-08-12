#include <iostream>

#define int long long

inline void submit(bool yes) {
    std::cout << (yes ? "It is a kind of magic" : "There are no miracles in life");
}

signed main() {
    int a, b, c, x, y, z; 
    std::cin >> a >> b >> c >> x >> y >> z;
    int nx = x - std::min(a, x);
    int na = a - std::min(a, x);
    int ny = y - std::min(b, y);
    int nb = b - std::min(b, y);
    if (nx) {
        if (c >= nx) {
            c -= nx;
            nx = 0;
        } else { 
            submit(0);
            return 0;
        }
    }
    if (ny) {
        if (c >= ny) {
            c -= ny;
            ny = 0;
        } else { 
            submit(0);
            return 0;
        }
    }
    submit(na + nb + c >= z);
}