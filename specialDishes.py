def isSubseq(a, b):
	j = 0
	for c in a:
		while j < len(b) and b[j] != c:
			j += 1
		if j == len(b):
			return False
		j += 1
	return True

def test(s):
	if len(s) <= 1:
		return "NO"
	n = len(s)
	if isSubseq(s[: n / 2], s[n / 2: ]) or \
		isSubseq(s[(n + 1) / 2 : ], s[: (n + 1 ) / 2]):
		return "YES"
	return "NO"



d = int(raw_input())
for i in xrange(d):
	print test(raw_input())



