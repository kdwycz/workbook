# coding = utf-8
__author__ = 'kdwycz'

fr = open('./test.cpp','r')
NUM = '0123456789.'
CHAR = '_qwertyuioplkjhgfdsazxcvbnmQWERTYUIOPLKJHGFDSAZXCVBNM0123456789'
KEY = ('void', 'main', 'int', 'float', 'if', 'else', 'return')

keyword = []
identifier = []

for line in fr.readlines():
    j = 0
    l = len(line)
    while (j<l):
        s = ''
        if (line[j] not in NUM) and (line[j] in CHAR):
            while (j+1<l and line[j] in CHAR):
                s += line[j]
                j += 1
            if s in KEY:
                print('(关键字,' + s + ')', end = ' ')
            else:
                print('(标识符,' + s + ')', end = ' ')
        j += 1

print ()