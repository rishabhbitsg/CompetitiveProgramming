for t in xrange(input()):
	a = raw_input()
	b = raw_input()
	type1 = type2 = type3 = type4 = 0
	for i in xrange(len(a)):
		if a[i] == '1' and b[i] == '0':
			type1 += 1
		elif a[i] == '0' and b[i] == '1':
			type2 += 1
		elif a[i] == '0' and b[i] == '0':
			type3 += 1
		else:
			type4 += 1
	ans = max(type1, type2)
	flag = False
	if type1 == 0 and type4 == 0:
		flag = True
	if type2 == 0 and type3 == 0:
		flag = True
	#print type1, type2, type3, type4
	if not flag:
		print "Lucky Chef"
		print ans
	else:
		print "Unlucky Chef"