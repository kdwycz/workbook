# coding = utf-8
__author__ = 'kdwycz'

fr = open('./test.cpp','r')
NUM = '0123456789.'
CHAR = '_qwertyuioplkjhgfdsazxcvbnmQWERTYUIOPLKJHGFDSAZXCVBNM0123456789'

numset = set([])
ideset = set([])

for line in fr.readlines():
    j = 0
    l = len(line)
    while (j<l):
        s = ''
        if line[j] in NUM:
            while (j+1<l and line[j] in NUM):
                s += line[j]
                j += 1
            numset.add(s)
        elif line[j] in CHAR:
            while (j+1<l and line[j] in CHAR):
                s += line[j]
                j += 1
            ideset.add(s)
        j += 1

print (u'分析程序出现数字有: ', numset)
print ()
print (u'分析程序出现标识符有: ', ideset)
