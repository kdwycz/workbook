# coding = utf-8
__author__ = 'kdwycz'

def Check(s):
	if ddict[s] == '^':
		return True
	else:
		for i,ch in enumerate(ddict[s]):
			if ddict.get(ch):
				if not Check(ch):
					return False
				return True
	return False

fr = open('./data','r')
ddict = {}
f = []

print("\n读入的产生式为：")
for line in fr.readlines():
	line = line.strip()
	print(line)
	(key,value) = line.split('-->')
	ddict[key] = value

for k in ddict:
	if Check(k):
		f.append(k)

print("\n导空符为：")
print(f)