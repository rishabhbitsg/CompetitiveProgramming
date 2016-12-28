for t in xrange(input()):
	s = raw_input().strip()
	if s.count("0") == 1 or s.count("1") == 1:
		print "Yes"
	else:
		print "No"
	