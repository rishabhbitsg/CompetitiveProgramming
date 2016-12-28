t = input()
for i in xrange(t):
	a = raw_input().strip()
	b = raw_input().strip()

	i1 = i2 = 0
	j1 = len(a) 
	j2 = len(b)
	
	s = ''

	while i1 < j1 and i2 < j2:
		if a[i1] < b[i2]:
			s += a[i1]
			i1 += 1
		elif a[i1] > b[i2]:
			s += b[i2]
			i2 += 1
		else:
			f1 = i1 
			f2 = i2

			while f1 < j1 and f2 < j2 and a[f1] == b[f2] and a[f1] <= a[f1 - 1]:
				f1 += 1
				f2 += 1
			f1 -= 1
			f2 -= 1

			#print f1, f2
			if f1 == j1 - 1:
				s += b[i2 : f2 + 1]
				i2 = f2 + 1
			elif f2 == j2 - 1:
				s += a[i1 : f1 + 1]
				i1 = f1 + 1
			elif a[f1 + 1] < b[f2 + 1]:
				s += a[i1 : f1 + 1]
				i1 = f1 + 1
			elif a[f1 + 1] > b[f2 + 1]:
				s += b[i2 : f2 + 1]
				i2 = f2 + 1
			else:
				s += a[i1 : f1 + 1] * 2
				i1 = f1 + 1
				i2 = f2 + 1


	while i1 < j1:
		s += a[i1]
		i1 += 1
	while i2 < j2:
		s += b[i2]
		i2 += 1

	print s