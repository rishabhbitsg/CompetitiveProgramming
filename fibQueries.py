fib = {}
def fibonacci(n):
	if n <= 0:
		return 0
	if n <= 2:
		return 1
	a = n / 2
	b = n - a
	ans = fibonacci(a) * fibonacci(b + 1) + fibonacci(a - 1) * fibonacci(b)
	fib[n] = ans
	return ans