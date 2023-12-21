import sys, os

n = len(sys.argv)
if (n > 2):
    raise Exception("Too many args!");
else:
    template = r'// ' + sys.argv[1] + r'''
#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main() {
        
    return 0;
}
'''
    link = sys.argv[1]
    i = -1
    cnt = 0
    idx = 0
    while cnt != 3:
        if (link[i] == '/'):
            cnt+=1
            if cnt == 2:
                idx = i
        i-=1
    i+=2
    problemNumber = link[i:idx]
    problemLetter = link[-1]
    file = open('./Codeforces/' + problemNumber + problemLetter + '.cpp', 'w')
    file.write(template)