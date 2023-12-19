// https://codeforces.com/problemset/problem/1907/C
#include <bits/stdc++.h>
using namespace std;
int t, n, freq[26]; string a;

int main() {
    cin >> t;
    while (t--) {
        cin >> n >> a; memset(freq, 0, sizeof(freq));
        for (int i = 0; i < n; ++i) freq[a[i] - 'a']++;
        char want; int mx = 0;
        for (int i = 0; i < 26; ++i)
            if (mx < freq[i]) mx = freq[i], want = i + 'a';
        int left = 0, other = 0;
        for (int i = 0; i < n; ++i) {
            if (a[i] == want) (other ? other-- : left++);
            else (left ? left-- : other++);
        }
        cout << left + (other&1) << endl;
    }
    return 0;
}