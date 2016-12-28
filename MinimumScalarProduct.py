for t in xrange(input()):
	n = input()
	x = map(int, raw_input().strip().split())
	y = map(int, raw_input().strip().split())
	x.sort()
	y.sort(reverse = True)
	ans = 0
	for i in xrange(n):
		ans += x[i] * y[i]

	print "Case #{}: {}".format(t + 1, ans)
