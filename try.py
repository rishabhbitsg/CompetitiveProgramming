def pow(A):
	n = len(A)
	A2 = [[0] * n for i in xrange(n)]
	for i in xrange(n):
		for j in xrange(n):
			for k in xrange(n):
				A2[i][j] += A[i][k] + A[k][j]
	return A2
	
n = int(raw_input())
A = [[0] * n for i in xrange(n)]
for i in xrange(n):
	for j in xrange(n):
		A[i] = map(int, raw_input().split())
A = pow(A)
A = pow(A)
ans = 0
for i in xrange(n):
	ans += A[i][i]
print ans / 24