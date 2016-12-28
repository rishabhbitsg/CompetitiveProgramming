for t in xrange(input()):
	n = input()
	candies = [[0] * 6 for i in xrange(n)]
	score = [0] * n 
	for i in xrange(n):
		inp = map(int, raw_input().strip().split())
		score[i] = inp[0]
		for type in inp[1 : ]:
			candies[i][type - 1] += 1
	
	for i in xrange(n):
		l = candies[i][ : ]
		l.sort(reverse=True)
		score[i] += l[-1] * 4
		temp = l[-1]
		l = [x - temp for x in l[ : -1]]
		
		score[i] += l[-1] * 2
		temp = l[-1]
		l = [x - temp for x in l[ : -1]]
		
		score[i] += l[-1] * 1
		temp = l[-1]
		l = [x - temp for x in l[ : -1]]

	winVal = max(score)

	if score.count(winVal) > 1:
		print "tie"
	elif score.index(winVal) == 0:
		print "chef"
	else:
		print score.index(winVal) + 1



