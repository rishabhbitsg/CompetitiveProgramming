n, k = list(map(int, input().split()))
a = list(map(int, input().split()))
b = list(map(int, input().split()))
maxElem = max(max(b), abs(min(b)))
ans = 0
for i in range(n):
	ans += a[i] * b[i]

ans -= k * 2 * maxElem

print(ans)