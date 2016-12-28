def dfs(u):
	visited[u] = 1
	l = [u]
	ans = True
	while not len(l) == 0:
		v = l.pop()
		for i in xrange(n):
			if g[v][i] == 1:
				if visited[v] == visited[i]:
					ans = False
					break
				elif visited[i] == 0:
					if visited[v] == 1:
						visited[i] = 2
					else:
						visited[i] = 1
					l.append(i)
		if not ans:
			break
	return ans


for t in xrange(input()):
	n, m = map(int, raw_input().strip().split())
	g = [[1] * n for i in xrange(n)]
	for i in xrange(n):
		g[i][i] = 0

	for i in xrange(m):
		a, b = map(int, raw_input().strip().split())
		g[a - 1][b - 1] = 0
		g[b - 1][a - 1] = 0

	
	# for i in xrange(n):
	# 	for j in xrange(n):
	# 		print g[i][j],
	# 	print

	visited = [0] * n

	possible = True
	
	for i in xrange(n):
		if visited[i] == 0:
			possible = dfs(i)
			if not possible:
				break

	if possible:
		print "YES"	
	else:
		print "NO"

