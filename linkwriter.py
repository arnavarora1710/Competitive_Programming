from os import listdir
from os.path import isfile, join

mypath = './Codeforces'
onlyfiles = [f for f in listdir(mypath) if isfile(join(mypath, f))]
for file in onlyfiles:
    path = file
    f = open('./Codeforces/' + file, 'r+')
    text = f.read()
    if (text[0] != '/'):
        f.seek(0)
        problemnum = ""
        problemlett = ""
        i = 0
        while (path[i].isdigit()):
            problemnum += path[i]
            i+=1
        while (path[i] != '.'):
            problemlett += path[i]
            i+=1
        addend = '// https://codeforces.com/problemset/problem/' + problemnum + '/' + problemlett + '\n'
        f.write(addend + text)  
    f.close()