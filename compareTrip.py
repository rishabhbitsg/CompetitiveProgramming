def giveScore(a, b):
	global scoreA, scoreB
	if a > b:
		scoreA += 1
	elif a < b:
		scoreB += 1

a0, a1, a2 = map(int, raw_input().split())
b0, b1, b2 = map(int, raw_input().split())

scoreA = scoreB = 0
giveScore(a0, b0)
giveScore(a1, b1)
giveScore(a2, b2)

print scoreA, scoreB