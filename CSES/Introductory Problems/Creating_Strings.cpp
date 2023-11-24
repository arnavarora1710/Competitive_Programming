#include <bits/stdc++.h>
using namespace std;
string a; set<string> s;

int main() {
    cin >> a; sort(a.begin(), a.end()); s.insert(a);
    while (next_permutation(a.begin(), a.end())) s.insert(a);
    cout << s.size() << endl;
    for (auto& v : s) cout << v << endl;
    return 0;
}