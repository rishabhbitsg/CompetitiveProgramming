n, q = map(int, raw_input().split())
a = map(int, raw_input().split())
lo = min(a)
hi = max(a)
for i in xrange(q):
	t = int(raw_input())
	if t >= lo and t <= hi:
		print "Yes"
	else:
	 print "No"