import heapq

heap = []
resultStr = []
n = input()
for i in xrange(n):
	inp = raw_input().split()
	if inp[0] == "insert":
		heapq.heappush(heap, int(inp[1]))
		resultStr.append(inp[0] + " " + inp[1])
	elif inp[0] == "getMin":
		while len(heap) > 0 and heap[0] < int(inp[1]):
			heapq.heappop(heap)
			resultStr.append("removeMin")
		if (len(heap) == 0 or heap[0] > int(inp[1])):
			heapq.heappush(heap, int(inp[1]))
			resultStr.append("insert " + inp[1])
		resultStr.append(inp[0] + " " + inp[1])
	else:
		if len(heap) > 0:
			heapq.heappop(heap)
		else:
			resultStr.append("insert 0")
		resultStr.append(inp[0])

print len(resultStr)
for result in resultStr:
	print result