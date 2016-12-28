for t in xrange(input()):
	n = input()
	a = map(int, raw_input().split())
	d = {}
	
	MAX = 75 * 10 ** 4
	M = 10 ** 9 + 7
	a.sort()
	for i in xrange(n):
		d[a[i]] = i

	i = n - 1
	ans = [0] * n
	while i >= 0:
		curr = a[i]
		ans[i] = 1
		for j in xrange(curr * 2, a[n - 1] + 1, curr):
			if j in d:
				ans[i] = (ans[d[j]] + ans[i]) % M
		i -= 1
	# print ans
	# print d
	fAns = 0
	for i in ans:
		fAns = (fAns + i) % M
	print fAns	