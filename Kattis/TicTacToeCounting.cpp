#include <bits/stdc++.h>
using namespace std;

bool checkWin(string& s, char c) {
    int ans = 0;

    if (!(s[0] == c && s[1] == c && s[2] == c)) ans--;
    if (!(s[3] == c && s[4] == c && s[5] == c)) ans--;
    if (!(s[6] == c && s[7] == c && s[8] == c)) ans--;
    if (!(s[0] == c && s[3] == c && s[6] == c)) ans--;
    if (!(s[1] == c && s[4] == c && s[7] == c)) ans--;
    if (!(s[2] == c && s[5] == c && s[8] == c)) ans--;
    if (!(s[0] == c && s[4] == c && s[8] == c)) ans--;
    if (!(s[2] == c && s[4] == c && s[6] == c)) ans--;

    return (ans + 8 > 0);
}

int xTurn = 1, oTurn = 2;

int isValid(string& s) {
    int x = 0, o = 0;

    for (int i = 0; i < 9; ++i) {
        if (s[i] == 'X') x++;
        else if (s[i] == 'O') o++;
    }

    bool xWins = checkWin(s, 'X'), oWins = checkWin(s, 'O');

    if (xWins && oWins) return 0;
    else if (xWins && x != o + 1) return 0;
    else if (oWins && x != o) return 0;
    else if (x != o && x != o + 1) return 0;
    else {
        if (x == o) return xTurn;
        else if (x > o) return oTurn;
        else return xTurn;
    }
}

bool x = 1, o = 0;
map<pair<string, bool>, pair<int, int> > m;
pair<int, int> rec(string s, bool turn) {
    
    pair<string, bool> input = make_pair(s, turn);
    if (m.count(input)) return m[input];

    pair<int, int> res = make_pair(0, 0);

    if (!isValid(s)) return m[input] = res;

    bool x_wins = checkWin(s, 'X'), o_wins = checkWin(s, 'O');
    if (x_wins) {
        res.first += 1;
        return m[input] = res;
    }
    else if (o_wins) {
        res.second += 1;
        return m[input] = res;
    }

    for (int i = 0; i < 9; ++i) {
        if (s[i] == '.') {
            if (turn) {
                s[i] = 'X';
                pair<int, int> result = rec(s, o);
                res.first += result.first; res.second += result.second;
            }
            else {
                s[i] = 'O';
                pair<int, int> result = rec(s, x);
                res.first += result.first; res.second += result.second;
            }
            s[i] = '.';
        }
    }

    return m[input] = res;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    rec(".........", xTurn);

    int t; cin >> t;
    while (t--) {
        string s; cin >> s;
        if (!isValid(s)) cout << "-1 -1\n";
        else {
            pair<int, int> res = make_pair(0, 0);
            int turn = isValid(s);
            if (turn == oTurn) {
                res.first += m[make_pair(s, o)].first; res.second += m[make_pair(s, o)].second;
            }
            else if (turn == xTurn) {
                res.first += m[make_pair(s, x)].first; res.second += m[make_pair(s, x)].second;
            }
            cout << res.first << " " << res.second << endl;
        }
    }
    return 0;
}