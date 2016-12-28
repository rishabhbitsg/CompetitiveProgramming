while(True):
	n =  int(input())
	if not n:
		break
	rows = [''] * n
	for i in range(n):
		rows[i] = input().strip()

	voids = [25 - row.count(' ') for row in rows]
	m = max(voids)
	res = [m - i for i in voids]
	#print(voids)
	#print(res)
	print(sum(res))
