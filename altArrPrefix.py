for t in xrange(int(raw_input())):
	l = []
	n = int(raw_input())
	for x in raw_input().split():
		l.append(int(x))
	i = 0
	res = [0] * n
	while i < n:
		j = i + 1
		while j < n:
			if l[j - 1] * l[j] > 0:
				break
			j += 1
		curr = j - i
		for k in xrange(i, j):
			res[k] = curr
			curr -= 1
		i = j
	for num in res:
		print num, 
	print
