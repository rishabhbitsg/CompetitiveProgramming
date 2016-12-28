for t in xrange(input()):
	n = input()
	b = map(int, raw_input().split())
	a = map(int, raw_input().split())
	c = sum(a) + sum(b)
	marked = [False] * n
	if (c % n == 0):
		c /= n
		flag = True
		for i in xrange(n): 
			if a[i] == c:
				pass 
			elif i > 0 and not marked[i - 1] and a[i] + b[i - 1] == c:
				marked[i - 1] = True;
			elif not marked[i] and a[i] + b[i] == c:
				marked[i] = True;
			elif i < n - 1 and not marked[i + 1] and a[i] + b[i + 1] == c:
				marked[i + 1] = True;
			elif i > 0 and not marked[i - 1] and not marked[i] and a[i] + b[i - 1] + b[i] == c:
				marked[i] = marked[i - 1] = True;
			elif i > 0 and i < n - 1 and not marked[i - 1] and not marked[i + 1] and a[i] + b[i - 1] + b[i + 1] == c:
				marked[i - 1] = marked[i + 1] = True;
			elif i < n - 1 and not marked[i + 1] and not marked[i] and a[i] + b[i + 1] + b[i] == c:
				marked[i] = marked[i + 1] = True;
			elif i > 0 and i < n - 1 and not marked[i + 1] and not marked[i - 1] and not marked[i] and a[i] + b[i + 1] + b[i - 1] + b[i] == c:
				marked[i] = marked[i - 1] = marked[i + 1] = True;
			else:
				flag = False;
				break;
		if flag: 
			print c
		else:
			print -1
	else:
		print -1