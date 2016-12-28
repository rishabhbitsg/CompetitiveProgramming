m = 1000000007
def mmi(a, m):
	return fast_pow(a, m - 2, m)
def fast_pow(base, n, m):
	if n == 0:
		return 1
	elif n == 1:
		return base
	halfN = fast_pow(base, n / 2, m)
	if n % 2 == 0:
		return (halfN * halfN) % m
	else:
		return (((halfN * halfN) % m) * base) % m

for t in xrange(input()):
	n, k = map(int, raw_input().split())
	a = map(int, raw_input().split())
	old_n = n
	n = n - a.count(0)
	if n == 0:
		print 1
	elif n < old_n:
		ans = [1] * (n + 1)
		for i in xrange(1, n / 2 + 2):
			ans[i] = (((ans[i - 1] % m) * ((n + 1 - i) % m) % m) * (mmi(i, m) % m)) % m
			ans[n - i] = ans[i]
		for i in xrange(1, n + 1):
			ans[i] = ((ans[i] % m) + (ans[i - 1] % m)) % m
		if k > n:
			print ans[n]
		else:
			print ans[k]
	else:
		ans = [1] * (n + 1)
		for i in xrange(1, n / 2 + 2):
			ans[i] = (((ans[i - 1] % m) * ((n + 1 - i) % m) % m) * (mmi(i, m) % m)) % m
			ans[n - i] = ans[i] 
		for i in xrange(2, n + 1):
			ans[i] = ((ans[i] % m) + (ans[i - 2] % m)) % m
		if k > n:
			if k % 2 == 0:
				if n % 2 == 0:
					print ans[n]
				else:
					print ans[n - 1]
			else:
				if n % 2 == 0:
					print ans[n - 1]
				else:
					print ans[n]
		else:
			print ans[k]