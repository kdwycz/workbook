# coding = utf-8
__author__ = 'kdwycz'

str = input()
state = 'A'
error = 0
for i in range(0,len(str)):
	if error != 0:
		break
	if str[i] == '0':
		if state == 'A':
			state = 'B'
		elif state == 'B':
			state = 'D'
		elif state == 'C':
			state = 'D'
		elif state == 'D':
			state = 'D'
		else:
			error = i+1
	elif str[i] == '1':
		if state == 'A':
			state = 'C'
		elif state == 'B':
			state = 'D'
		elif state == 'C':
			state = 'A'
		elif state == 'D':
			state = 'D'
		else:
			error = i+1
	else:
		error = i+1

if error != 0:
	print(u'字符串在第%d位出现非法字符' %error)
elif state != 'D':
	print(u'字符串未终止')
else:
	print(u'字符串合法')
