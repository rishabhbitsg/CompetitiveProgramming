q = input()
for t in xrange(q):
	k = input()
	a = raw_input()
	b = raw_input()
	c = raw_input()
	a = bin(int(a, 16))[2 : ]
	b = bin(int(b, 16))[2 : ]
	c = bin(int(c, 16))[2 : ]
	length = max(len(a), len(b), len(c))
	a = '0' * (length - len(a)) + a
	b = '0' * (length - len(b)) + b
	c = '0' * (length - len(c)) + c
	a = list(a)
	b = list(b)
	c = list(c)
	# print "a = ", a, " b = ", b
	used = 0
	for i in xrange(length):
		if (int(a[i]) | int(b[i]) != int(c[i])):
			if (c[i] == '0'):
				if a[i] == '1':
					a[i] = '0'
					used += 1
				if b[i] == '1':
					b[i] = '0'
					used += 1
			else:
				b[i] = '1'
				used += 1
	if used <= k:
		left = k - used
		if left > 0:
			for i in xrange(length - 1, -1, -1):
				if left == 0:
					break
				if c[i] == '1':
					if a[i] == '1':
						if b[i] == '0' and left >= 2:
							a[i] = '0'
							b[i] = '1'
							left -= 2
						elif b[i] == '1':
							a[i] = '0'
							left -= 1

				# print "aBit = ", aBit, " bBit = ", bBit, " cBit = ", cBit	
		print hex(int(''.join(a), 2))[2 : ].upper()
		print hex(int(''.join(b), 2))[2 : ].upper()
	else:
		print -1