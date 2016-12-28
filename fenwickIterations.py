for t in xrange(input()):
	l1, l2, l3, n = raw_input().strip().split()
	n = int(n)
	s = l1 + l2 * n + l3
	b = int(s, 2)
	ans = 0
	while b != -1:
		ans += 1
		b = (b & (b + 1)) - 1

	print ans
