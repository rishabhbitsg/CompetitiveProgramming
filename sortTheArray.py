def isSorted():
	for i in xrange(n - 1):
		#print i
		if a[i] > a[i + 1]:
			return False
	return True

n = input()
a = map(int, raw_input().strip().split())


if isSorted():
	print "yes"
else:

	for i in xrange(n - 1):
		if a[i] > a[i + 1]:
			break
	#print i
	for j in xrange(i, n):
		if a[i] < a[j]:
			break
	if j == n - 1 and a[i] > a[j]:
		j += 1
	j -= 1
	#print i, j
	b = a[:]
	a[i], a[j] = a[j], a[i]
	#print a


	if isSorted():
		print "yes"
		print "swap", i + 1, j + 1
	else:
		a = b[:]
		#print i
		j = i + 1
		while j < n and a[j] < a[j - 1]:
			j += 1

		j -= 1
		#print j
		if i == 0:
			a[i : j + 1] = a[j : : -1]
		else:
			a[i : j + 1] = a[j : i - 1 : -1]

		#print a
		if isSorted():
			print "yes"
			print "reverse", i + 1, j + 1
		else:
			print "no"