for t in xrange(input()):
	x1, y1, x2, y2 = map(int, raw_input().split())
	if (x1 == x2):
		if y1 > y2:
			print "down"
		else:
			print "up"
	elif (y1 == y2):
		if x1 < x2:
			print "right"
		else:
			print "left"
	else:
		print "sad"