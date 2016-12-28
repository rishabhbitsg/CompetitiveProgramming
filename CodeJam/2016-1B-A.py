import string

def solve():
	found = True
	while found:
		found = False
		if d['Z'] > 0:
			found = True
			digit[0] += d['Z']
			d['E'] -= d['Z']
			d['R'] -= d['Z']
			d['O'] -= d['Z']
			d['Z'] = 0

		elif d['W'] > 0:
			found = True
			digit[2] += d['W']
			d['T'] -= d['W']
			d['O'] -= d['W']
			d['W'] = 0

		elif d['U'] > 0:
			found = True
			digit[4] += d['U']
			d['F'] -= d['U']
			d['O'] -= d['U']
			d['R'] -= d['U']
			d['U'] = 0

		elif d['X'] > 0:
			found = True
			digit[6] += d['X']
			d['S'] -= d['X']
			d['I'] -= d['X']
			d['X'] = 0

		elif d['O'] > 0:
			found = True
			digit[1] += d['O']
			d['N'] -= d['O']
			d['E'] -= d['O']
			d['O'] = 0

		elif d['F'] > 0:
			found = True
			digit[5] += d['F']
			d['I'] -= d['F']
			d['V'] -= d['F']
			d['E'] -= d['F']
			d['F'] = 0

		elif d['V'] > 0:
			found = True
			digit[7] += d['V']
			d['S'] -= d['V']
			d['E'] -= 2 * d['V']
			d['N'] -= d['V']
			d['V'] = 0

		elif d['R'] > 0:
			found = True
			digit[3] += d['R']
			d['T'] -= d['R']
			d['H'] -= d['R']
			d['E'] -= 2 * d['R']
			d['R'] = 0

		elif d['G'] > 0:
			found = True
			digit[8] += d['G']
			d['E'] -= d['G']
			d['I'] -= d['G']
			d['H'] -= d['G']
			d['T'] -= d['G']
			d['G'] = 0

		elif d['I'] > 0:
			digit[9] += d['I']

	result = "Case #{}: ".format(t + 1)
	for i in xrange(10):
		result += str(i) * digit[i]		
	print result
for t in xrange(input()):
	s = raw_input().strip()
	d = {i : 0 for i in string.uppercase}
	for char in s:
		d[char] += 1

	digit = [0] * 10
	solve()

