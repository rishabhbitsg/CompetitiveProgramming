n = int(input())
teams = input().split()
teams.sort(reverse = True)
nameToInt = {}
intToName = {}
i = 0
for team in teams:
	nameToInt[team] = i
	intToName[i] = team
	i += 1

gFor = [0] * n
gAgainst = [0] * n
points = [0] * n
gDiff = [0] * n
match = {}

m = int(input())

flag = False
for i in range(m):
	t1, t2, s1, s2 = input().split()
	# print(t1, t2, s1, s2)
	s1 = int(s1)
	s2 = int(s2)
	t1 = nameToInt[t1]
	t2 = nameToInt[t2]

	if (t1, t2) in match or (t2, t1) in match:
		# print("t1 = {}, t2 = {}".format(intToName[t1], intToName[t2]))
		flag = True
		break

	if t1 == t2:
		# print("t1 = {}, t2 = {}".format(intToName[t1], intToName[t2]))
		flag = True
		break


	gFor[t1] += s1
	gAgainst[t1] += s2
	gDiff[t1] += s1 - s2

	gFor[t2] += s2
	gAgainst[t2] += s1
	gDiff[t2] += s2 - s1

	if (s1 > s2):
		points[t1] += 2
	elif s1 == s2:
		points[t1] += 1
		points[t2] += 1
	else:
		points[t2] += 2


if flag:
	print("Invalid Input")
else:
	l = []
	for i in range(n):
		l.append((points[i], gDiff[i], gFor[i], i))
	l.sort(reverse = True)
	for i in l:
		print(intToName[i[3]])








