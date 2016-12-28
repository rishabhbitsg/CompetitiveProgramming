def dfs(i, j):
	if i < 0 or j < 0 or i >= len(g) or j >= len(g[i]) or visited[i][j]:
		return -1  
	else:
		ans = 1
		visited[i][j] = True

		ret = dfs(i - 1, j)
		if ret != -1:
			ans += ret

		ret = dfs(i + 1, j)
		if ret != -1:
			ans += ret

		ret = dfs(i, j - 1)
		if ret != -1:
			ans += ret

		ret = dfs(i, j + 1)
		if ret != -1:
			ans += ret

		ret = dfs(i + 1, j + 1)
		if ret != -1:
			ans += ret

		ret = dfs(i - 1, j - 1)
		if ret != -1:
			ans += ret

		ret = dfs(i - 1, j + 1)
		if ret != -1:
			ans += ret

		ret = dfs(i + 1, j - 1)
		if ret != -1:
			ans += ret

		return ans


path = input()
f = open(path, 'r')

g = []

for line in f:
	g.append(line[ : -1])

f.close()

# print(g)

ans = []
visited = []
for i in range(len(g)):
	l = []
	for j in range(len(g[i])):
		if (g[i][j] == " "):
			l.append(True)
		else:
			l.append(False)
	visited.append(l)

for i in range(len(g)):
	for j in range(len(g[i])):
		ret = dfs(i, j)
		if ret != -1:
			ans.append(ret)

ans.sort(reverse = True)

for i in range(len(ans)):
	print("continent {}: {}".format(i + 1, ans[i]), end="")
print("Number of continents: {}".format(len(ans)), end="")