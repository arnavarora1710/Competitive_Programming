// https://codeforces.com/problemset/problem/1514/C
#include <bits/stdc++.h>
using namespace std;

int main() {
    int n; cin >> n; set<int> a;
    long long prod = 1;
    for (int i = 1; i < n - 1; ++i) {
        if (gcd(i, n) == 1) {
            prod = (prod * i) % n;
            a.insert(i);
        }
    }

    // last co-prime : (n - 1) is always co-prime to n
    if ((prod * (n - 1)) % n == 1) a.insert(n - 1);

    cout << a.size() << endl;
    for (auto& v : a) cout << v << " ";
    return 0;
}

// bonus : solve for length of subsequence for n <= 1e12
// https://codeforces.com/blog/entry/89810?#comment-782069