for t in xrange(input()):
	s = raw_input().strip()
	n = len(s) / 2
	if len(s) % 2 != 0:
		n += 1	
	possible = True
	s = list(s)
	for i in xrange(n):
		if s[i] != "." and s[len(s) - 1 - i] != "." and s[i] != s[len(s) - 1 - i]:
			possible = False
			break
		elif s[i] == "." and s[len(s) - 1 - i] != ".":
			s[i] = s[len(s) - 1 - i]
		elif s[i] != "." and s[len(s) - 1 - i] == ".":
			s[len(s) - 1 - i] = s[i]
		elif s[i] == "." and s[len(s) - 1 - i] == ".":
			s[i] = s[len(s) - 1 - i] = "a"

	if possible:
		print "".join(s)
	else:
		print -1