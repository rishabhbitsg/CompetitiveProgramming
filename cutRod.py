def cutRod(n, p):
	r = [-1] * (n + 1)
	s = [-1] * (n + 1)
	l = [-1] * (n + 1)
	r[0] = 0
	for i in xrange(1, n + 1):
		q = -1
		#print "-------------------"
		#print "i =", i
		for j in xrange(1, i + 1):
			if q < p[j - 1] + r[i - j] - l[i - j] - 1:
				q = p[j - 1] + r[i - j] - l[i - j] - 1
				s[i] = j
				l[i] = l[i - j] + 1
			#print "q =", q, " x =",  p[j - 1] + r[i - j]
		r[i] = q
		#print 

	for i in xrange(n + 1):
		print r[i],
	print
	return (r, s)

def printSol(n, p):
	r, s = cutRod(n, p)
	#print r 
	#print s
	for i in xrange(1, n + 1):
		print "-------------"
		print "i =", i
		while i > 0:
			print s[i], 
			i -= s[i]
		print 

n = int(raw_input())
p = raw_input().split()
p = [int(x) for x in p]
#print p 	
cutRod(n, p)
printSol(n, p)
