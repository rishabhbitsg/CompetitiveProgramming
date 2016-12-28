for t in xrange(int(raw_input())):
	n = int(raw_input())
	l = []
	for num in raw_input().split():
		l.append(int(num))
	winner = 0
	while len(l) > 0:
		result = 0
		for i in xrange(len(l)):
			result ^= l[i]
		if result == 0:
			break
		found = False
		for i in xrange(len(l)):
			if l[i] ^ result != 0:
				l.pop(i)
				found = True
				break
		if not found:
			winner = (winner + 1) % 2		
			break
		winner = (winner + 1) % 2

	print "First" if winner == 0 else "Second"

