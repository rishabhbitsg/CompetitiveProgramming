n, k = map(int, raw_input().split())
a = map(int, raw_input().split())

a = [x % k for x in a]
a.sort()
ans = 0
for i in xrange(1, k / 2 + 1):
	ans += max(a.count(i), a.count(k - i))

if a.count(0) > 0:
	ans += 1

if k % 2 == 0 and a.count(k / 2) > 0:
	ans -= a.count(k / 2) - 1

print ans