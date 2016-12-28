a, b, c, d = map(int, raw_input().split())
p1 = max(3 * a / 10, a - a / 250 * c)
p2 = max(3 * b / 10, b - b / 250 * d)
if p1 == p2:
	print "Tie"
elif p1 > p2:
	print "Misha"
else:
	print "Vasya"