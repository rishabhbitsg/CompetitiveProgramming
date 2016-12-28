from heapq import *

def convert(trip):
	hourDep = int(trip[0][ : 2])
	minDep = int(trip[0][3 : ])
	hourArr = int(trip[1][ : 2])
	minArr = int(trip[1][3 : ])
	return [hourDep * 60 + minDep, hourArr * 60 + minArr]

for t in xrange(input()):
	turnaround = input()
	na, nb = map(int, raw_input().strip().split())
	trips = []
	for i in xrange(na):
		trips.append([convert(raw_input().strip().split()), 0])

	for i in xrange(nb):
		trips.append([convert(raw_input().strip().split()), 1])

	trips.sort()

	trains = [[], []]
	start = [0, 0]

	for trip in trips:
		# print trip
		# print trains
		# print start
		d = trip[1]

		if trains[d] and trains[d][0] <= trip[0][0]:
			heappop(trains[d])
		else:
			start[d] += 1

		heappush(trains[(d + 1) % 2], trip[0][1] + turnaround)

		# print "\n" * 2
		# print trip
		# print trains
		# print start

	print "Case #{}: {} {}".format(t + 1, start[0], start[1])
