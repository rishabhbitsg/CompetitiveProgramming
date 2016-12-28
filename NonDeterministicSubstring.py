class NonDeterministicSubstring:
	def ways(self, a, b):
		sum = 0
		found = {}
		if len(b) <= len(a):
			for i in xrange(len(a) - len(b) + 1):
				for j in range(i, i + len(b)):
					flag = True
					if a[j] != b[j - i] and b[j - i] != '?':
						flag = False
						break
				if flag:
					print a[i : i + len(b)]
					if not a[i : i + len(b)] in found:
						found[a[i : i + len(b)]] = True
						sum += 1
		return sum

# obj = NonDeterministicSubstring()
# print obj.ways("00010001", "??")