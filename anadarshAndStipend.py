for t in xrange(input()):
	n = input()
	a = map(int, raw_input().split())
	grade = sum(a) / n
	if min(a) > 2 and max(a) == 5 and grade >= 4:
		print "Yes"
	else:
		print "No"