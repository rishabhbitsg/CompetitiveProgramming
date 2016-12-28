import string
digs = string.digits + string.letters

def int2base(x, base):
  if x < 0: sign = -1
  elif x == 0: return digs[0]
  else: sign = 1
  x *= sign
  digits = []
  while x:
    digits.append(digs[x % base])
    x /= base
  if sign < 0:
    digits.append('-')
  digits.reverse()
  return ''.join(digits)

for t in xrange(input()):
  k = input() - 1
  ans = int2base(k, 5)
  ans = ans.split()
  for i in xrange(len(ans)):
    ans[i] = str(2 * int(ans[i]))
  ans = "".join(ans)
  print ans