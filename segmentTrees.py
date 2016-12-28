import math
def initialize(node, lo, hi, m, a):
	if lo == hi:
		m[node] = lo
	else:
		initialize(2 * node + 1, lo, (lo + hi) / 2, m, a)
		initialize(2 * node + 2, (lo + hi) / 2 + 1, hi, m, a)
		if a[m[2 * node + 1]] <= a[m[2 * node + 2]]:
			m[node] = m[2 * node + 1]
		else:
			m[node] = m[2 * node + 2] 
def query(node, lo, hi, m, a, i, j):
	#print "lo =", lo, " hi =", hi
	if i > hi or j < lo:
		return -1
	if lo >= i and hi <= j:
		return m[node]
	p1 = query(2 * node + 1, lo, (lo + hi) / 2, m, a, i, j)
	p2 = query(2 * node + 2, (lo + hi) / 2 + 1, hi, m, a, i, j)
	result = -1
	if p1 == -1:
		result =  p2
	if p2 == -1:
		result =  p1
	if a[p1] <= a[p2]:
		result = p1
	else:
		result = p2
	#print "result = ", a[result]
	return result

a = [2, 3, 7, 5, 1, 6, 4, 5, 2]
m = [-1] * (4 * 2 ** int(math.log(9, 2)))
print len(m)
initialize(0, 0, 8, m, a)
print m
print query(0, 0, 8, m, a, 2, 7)
