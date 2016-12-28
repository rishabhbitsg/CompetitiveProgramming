for t in range(int(input())):
	s = int(input())
	se = {}
	for i in range(s):
		se[input().strip()] = True

	found = {}
	ans = 0

	q = int(input())
	for i in range(q):
		query = input().strip()
		if query not in found:
			found[query] = True

		if len(found) == s - 1:
			found = {}
			ans += 1

	print("Case #{}: {}".format(t + 1, ans)) 