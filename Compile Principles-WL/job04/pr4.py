# coding = utf-8
__author__ = 'kdwycz'

def nextsymbole():
	global link
	link += 1

def error(i):
	print("符号串在第%d个元素不合法" %i)
	exit()

def C():
	if s[link] == "c":
		nextsymbole()
		C()
		if s[link] == "c":
			nextsymbole()
		else:
			error(link)
	elif s[link] == "d":
		nextsymbole()
	else:
		error(link)	

def B():
	if s[link] == "b":
		nextsymbole()
		B()
		if s[link] == "e":
			nextsymbole()
		else:
			error(link)
	else:
		C()

def S():
	if s[link] == "a":
		nextsymbole()
		S()
		if s[link] == "e":
			nextsymbole()
		else:
			error(link)
	else:
		B()

if __name__ == "__main__":
	s = input("请输入以'$'结尾的符号串:\n")

	if s[len(s)-1] != "$":
		print("输入错误,请重新输入")
	else:
		link = 0
		S()
		print("字符串合法")