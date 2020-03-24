
yyy_=0



def xxx():
	global yyy_
	yyy=0

	yyy=10
	return 13


def main():
	global yyy_
	yyy_=11
	xxx()
	return yyy_



if __name__ == "__main__":
	import sys
	ret=main()
	sys.exit(ret)
