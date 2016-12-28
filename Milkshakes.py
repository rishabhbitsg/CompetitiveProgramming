for c in xrange(input()):
	n = input()
	m = input()
	customers = []
	for i in xrange(m):
		inp = map(int, raw_input().strip().split())
		t = inp[0]
		l = []
		for j in xrange(1, 2 * t + 1, 2):
			l.append((inp[j], inp[j + 1]))
		customers.append(l)
	result = [0] * n
	malted = {}
	impossible = False
	
	while True:
		for i in xrange(m):
			satisfied = False
			index = -1
			for j in customers[i]:
				if result[j[0] - 1] == j[1]:
					satisfied = True
					break
				elif j[1] == 1:
					index = j[0] - 1
			if not satisfied:
				break
		if satisfied:
			break
		elif index == -1:
			impossible = True
			break
		else:
			result[index] = 1


	print "Case #{}: ".format(c + 1),
	if not impossible:
		for i in xrange(n):
			print result[i],
		print
	else:
		print "IMPOSSIBLE"

