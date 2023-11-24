#include <bits/stdc++.h>
using namespace std;
string a; map<char, int> m;

int main() {
    cin >> a; for (int i = 0; i < a.size(); ++i) m[a[i]]++;
    int l = 0, r = a.size() - 1; char odd = ' ';
    for (auto& v : m) {
        int charCount = v.second;
        if (charCount&1) {
            if (odd != ' ') {cout << "NO SOLUTION"; return 0;}
            else odd = v.first, charCount--;
        }
        while (charCount) a[l++] = a[r--] = v.first, charCount -= 2;
    }
    if (odd != ' ') a[a.size() / 2] = odd;
    cout << a;
    return 0;
}