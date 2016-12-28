for t in xrange(int(raw_input())):
	h, m = map(int, raw_input().split())
	count = 0
	for i in xrange(h):
		for j in xrange(m):
			temp = str(i) + str(j)
			#print temp
			if temp.count(temp[0]) == len(temp):
				count += 1
	print count