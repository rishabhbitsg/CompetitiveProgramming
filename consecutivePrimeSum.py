from math import sqrt
MAX = 560000
def sieve():
	sum = 0
	for i in range(2, MAX):
		if isPrime[i] == -1:
			sum += i
			isPrime[i] = 1
			if sum != 2:
				sumList.append(sum)
			for i in range(i * i, MAX, i):
				isPrime[i] = 0

def isPrime2(a):
	if a % 2 == 0:
		return False
	for i in range(3, int(sqrt(a)) + 1, 2):
		if a % i == 0:
			return False
	return True

n = int(input())
isPrime = [-1] * (MAX)
isPrime[0] = isPrime[1] = 0
sumList = []
sieve()

sum = 2
ans = 0
# print(sumList[-1])
print(len(sumList))
for i in sumList:
	if i <= n and i < MAX and isPrime[i]:
		# print(sum)
		ans += 1
		# print(i)
	elif i <= n and isPrime2(i):
		ans += 1
	elif i > n:
		break

print(ans, end="")

