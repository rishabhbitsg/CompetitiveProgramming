import string
n = input()
l = []
for i in xrange(n):
	l.append(raw_input())
d = {}
for c in string.lowercase:
	for compound in l:
		if c in compound:
			if c in d:  
				d[c] += 1
			else:
				d[c] = 1

ans = 0
for k in d.keys():
	if d[k] == n:
		ans += 1
print ans
