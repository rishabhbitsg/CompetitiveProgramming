def dfsDivide(g, b):
	global dist, visited
	dist[b] = 0
	visited[b] = True
	i = 1
	for v in g[b]:
		dfs(g, v, 1, i)
		i += 1

def dfs(g, u, d, s):
	global dist, visited, side
	side[u] = s
	dist[u] = d
	visited[u] = True
	for v in g[u]:
		if not visited[v]:
			dfs(g, v, d + 1, s)

n, k = map(int, raw_input().split())
b = int(raw_input())
g = [[] for i in xrange(n + 1)]
for i in xrange(n - 1):
	x, y = map(int, raw_input().split())
	g[x].append(y)
	g[y].append(x)

product = [-1] * (n + 1)
for i in xrange(1, n + 1):
	product[i] = int(raw_input())

dist = [-1] * (n + 1)
visited = [False] * (n + 1)
side = [-1] * (n + 1)
dfsDivide(g, b)
minCity = {}
minSide = {}
maxCity = {}

for i in xrange(1, n + 1):
	p = product[i]
	s = side[i]
	if p in minCity:
		if i != b and dist[i] > dist[minCity[p]]:
			minCity[p] = i
	else:
		minCity[p] = i
	
	if (s, p) in minSide:
		if i != b and dist[i] > dist[minSide[(s, p)]]:
			minSide[(s, p)] = i
	else:
		minSide[(s, p)] = i

	if p not in maxCity:
		maxCity[p] = i


q = int(raw_input())
print maxCity
for i in xrange(q):	
	a, p1 = map(int, raw_input().split())
	s = side[a]
	if a == b:
		if p1 in maxCity:
			print maxCity[p1]
		else:
			print -1
	elif (s, p1) in minSide:
		print minSide[(s, p1)]
	elif p1 in minCity:
		print minCity[p1]
	else:
		print -1
