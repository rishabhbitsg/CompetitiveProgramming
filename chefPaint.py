for t in xrange(input()):
	n = input()
	a = map(int, raw_input().split())
	flag = True
	for i in xrange(2, len(a)):
		if a[i] == a[i - 1] and a[i - 1] == a[i - 2]:
			print "Yes"
			flag = False
			break
	if flag:
		print "No"