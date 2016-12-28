import collections

def preProcessMaxRow(A, n, m, a):
	for i in xrange(n):
		d = collections.deque()
		for k in xrange(a):
			while not len(d) == 0 and A[i][k] >= A[i][d[-1]]:
				d.pop()
			d.append(k)
		maxRow[i][k] = A[i][d[0]]
		for j in xrange(k + 1, m):	

			if not len(d) == 0 and d[0] <= j - a:
				d.popleft()

			while not len(d) == 0 and A[i][j] >= A[i][d[-1]]:
				d.pop()
			d.append(j)

			maxRow[i][j] = A[i][d[0]]

# def sparseMatrix(n, m):
# 	i = 0
# 	while 2 ** i <= n:
# 		j = 0
# 		while 2 ** j <= m:
# 			x = 0
# 			while x + 2 ** i - 1 < n:
# 				# print "x =", x
# 				y = 0
# 				while y + 2 ** j - 1 < m:
# 					# print "x =", x, " y =", y, " i =", i, " j =", j
# 					# print "n =", n, " m =", m
# 					if i == 0 and j == 0:
# 						M[x][y][i][j] = A[x][y]
# 					elif i == 0:
# 						M[x][y][i][j] = max(M[x][y][i][j - 1], M[x][y + 2 ** (j - 1)][i][j - 1])
# 					elif j == 0:
# 						M[x][y][i][j] = max(M[x][y][i - 1][j], M[x + 2 ** (i - 1)][y][i - 1][j])
# 					else:
# 						M[x][y][i][j] = max(M[x][y][i - 1][j - 1], M[x][y + 2 ** (j - 1)][i - 1][j - 1],
# 							M[x + 2 ** (i - 1)][y][i - 1][j - 1], M[x + 2 ** (i - 1)][y + 2 ** (j - 1)][i - 1][j - 1])
# 					y += 1
# 				x += 1
# 			j += 1
# 		i += 1

# def RMQ(x, y, x1, y1):
# 	k = int(math.log(x1 - x + 1, 2))
# 	l = int(math.log(y1 - y + 1, 2))
# 	ans = max(M[x][y][k][l], M[x1 - 2 ** k + 1][y][k][l], M[x][y1 - 2 ** l + 1][k][l], M[x1 - 2 ** k + 1][y1 - 2 ** l + 1][k][l])
# 	return ans

def summedArea(n, m):
	for i in xrange(n):
		for j in xrange(m):
			a = A[i][j]
			b = SA[i - 1][j] if i > 0 else 0
			c = SA[i][j - 1] if j > 0 else 0
			d = SA[i - 1][j - 1] if i > 0 and j > 0 else 0
			SA[i][j] = a + b + c - d


def sumSub(x, y, x1, y1):
	# print "x1 = ", x1, " y1 = ", y1
	a = SA[x1][y1]
	b = SA[x1][y - 1] if y > 0 else 0 
	c = SA[x - 1][y1] if x > 0 else 0
	d = SA[x - 1][y - 1] if x > 0 and y > 0 else 0
	return a - b - c + d

A = []
n, m = map(int, raw_input().split())
for i in xrange(n):
	A.append(map(int, raw_input().split()))

# M = [[[[-1] * int(math.log(m, 2) + 1) for d3 in xrange(int(math.log(n, 2) + 1))] for d2 in xrange(m)] for d1 in xrange(n)]

SA = [[-1 for y in xrange(m)] for x in xrange(n)]
#print M
# sparseMatrix(n, m)
summedArea(n, m)
#print "---------------"
#print M
#print RMQ(1, 0, 2, 3)
#print RMQ(0, 0, 2, 0)
#print sumSub(1, 0, 2, 2)
#print sumSub(1, 1, 2, 2)

# for i in xrange(n):
# 	for j in xrange(m):
# 		prin`t maxCol[i][j],
# 	print 

q = input()
for x in xrange(q):
	ans = float('inf')
	a, b = map(int, raw_input().split())
	maxRow = [[-1 for y in xrange(m)] for x in xrange(n)]
	preProcessMaxRow(A, n, m, b)
	ans = float("inf")
	for j in xrange(b - 1, m):
		d = collections.deque()

		for k in xrange(a):
			while len(d) > 0 and maxRow[k][j] >= maxRow[d[-1]][j]:
				d.pop()
			d.append(k)
		ans = min(ans, a * b * maxRow[d[0]][j] - sumSub(k - a + 1, j - b + 1, k, j))
		for i in xrange(k + 1, n):
			if len(d) > 0 and d[0] <= i - a:
				d.popleft()
			while len(d) > 0 and maxRow[i][j] >= maxRow[d[-1]][j]:
				d.pop()
			d.append(i)
			ans = min(ans, a * b * maxRow[d[0]][j] - sumSub(i - a + 1, j - b + 1, i, j))



	print ans			