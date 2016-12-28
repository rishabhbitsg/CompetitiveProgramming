for t in xrange(input()):
	n = input()
	a = map(int, raw_input().split())

	

	if n == 1:
		print "yes"
	else:

		isZero = 0 in a
		isOne = 1 in a
		isMinusOne = -1 in a
		tcount = {}
		for i in a:
			if i in tcount:
				tcount[i] += 1
			else:
				tcount[i] = 1
		
		count = 0
		for i in tcount.keys():
			if i != 0 and i != 1 and i != -1:
				count += tcount[i] 


		if isZero and isOne:
			if (not isMinusOne and count <= 1) or count == 0:
				print "yes"
			else:
				print "no"

		elif isOne:
			if (not isMinusOne and count <= 1) or count == 0:
				print "yes"
			else:
				print "no"

		elif isZero:
			if count == 0 and isMinusOne and tcount[-1] == 1:
				print "yes"
			elif not isMinusOne and count <= 1:
				print "yes"
			else:
				print "no"
		else:
			print "no"


