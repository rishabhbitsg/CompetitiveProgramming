import fractions
for t in xrange(input()):
	a, b, c, d = map(int, raw_input().split())
	g = fractions.gcd(c, d)
	diff = abs(a - b)
	i = (diff / g) * g
	j = i + g
	print min(abs(i - diff), j - diff)