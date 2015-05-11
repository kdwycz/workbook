# coding = utf-8
__author__ = 'kdwycz'

fr = open('./test.cpp','r')
TAB = 4 #Tab长度
NUM = '0123456789.'
CHAR = '_qwertyuioplkjhgfdsazxcvbnmQWERTYUIOPLKJHGFDSAZXCVBNM0123456789'
KEY = ('void', 'main', 'if', 'else', 'return')
DATATYPE = ('int', 'float', 'char', 'double')

identifier = []
declareVar = []
declare = False
specialequal = False

i = 1 #行号
for line in fr.readlines():
    tab = 0
    j = 0 #列号
    l = len(line)
    while (j<l):
        s = ''
        if (line[j] not in NUM) and (line[j] in CHAR):
            while (j+1<l and line[j] in CHAR):
                s += line[j]
                j += 1
            if s in KEY:
                pass
            elif s in DATATYPE:
                declare = True
            else:
                if declare == True and specialequal == False:
                    if s in declareVar:
                        print('警告：%s在第%d行%d列被重复声明' %(s,i,j))
                    else:
                        declareVar.append(s)
                else:
                    if s not in declareVar:
                        print('错误：未定义的变量%s在第%d行%d列' %(s,i,j+tab*(TAB-1)))
        specialequal = False
        if line[j] == ';':
            declare = False
        if line[j] == '\t':
            tab += 1
        if line[j] == '=':
        	specialequal = True
        j += 1
    i += 1