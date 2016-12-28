for t in xrange(input()):
	n = input()
	names = []
	for i in xrange(n):
		names.append(raw_input().strip())
	names.sort()
	# print names
	ans = ""
	currMax = 0
	for name in names:
		chars = {}
		curr = 0
		for char in name:
			# print char
			if char not in chars and not char is " ":	
				curr += 1
				chars[char] = None
			# print chars
		if curr > currMax:
			currMax = curr
			ans = name
	print "Case #" + str(t + 1) + ":", ans