import sys, os, subprocess

n = len(sys.argv)
if (n > 3):
    raise Exception("Too many args!");
elif (n < 3):
    raise Exception("Too less args!");
else:
    templateFile = open("./template.cpp")
    template = templateFile.read()
    print(template)
    type = sys.argv[2]
    link = sys.argv[1]
    i = -1
    cnt = 0
    idx = 0
    if type == 'c':
        while cnt != 3:
            if (link[i] == '/'):
                cnt+=1
                if cnt == 2:
                    idx = i
            i-=1
        i+=2
    elif type == 'p':
        while cnt != 2:
            if (link[i] == '/'):
                cnt+=1
                if cnt == 1:
                    idx = i
            i-=1
        i+=2
    problemNumber = link[i:idx]
    problemLetter = link[-1]
    if (link[-1] >= '0' and link[-1] <= '9'):
        problemLetter = link[-2] + link[-1]
    filepath = './Codeforces/' + problemNumber + problemLetter + '.cpp'
    file = open(filepath, 'w')
    file.write(template)
    file.close()
    subprocess.run(['code', filepath])