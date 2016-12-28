n = int(raw_input())

dp = {0 : 0}
next = {0 : None}

def quasiBin(i):
	for c in str(i):
		if c != '0' and c != '1':
			return False
	return True


def findSol(i):
	if i in dp:
		return dp[i]
	else:
		ans = float('inf')
		for j in xrange(i, 0, -1):
			if quasiBin(j):
				if ans > findSol(i - j) + 1:
					ans = findSol(i - j) + 1
					nxt = i - j
		dp[i] = ans
		next[i] = nxt
	return dp[i]

print findSol(n)
# print dp
# print next

while True:
	print n - next[n], 
	n = next[n]
	if not n:
		break

