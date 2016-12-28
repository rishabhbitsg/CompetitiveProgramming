n, k = map(int, raw_input().split())
num = raw_input()
num = list(num)
numOrig = num[:]

flag = True
for i in xrange(n / 2 + 1):
    if num[i] != num[n - i - 1]:
        if k > 0:
            num[i] = num[n - i - 1] = max(num[i], num[n - i - 1])
            k -= 1
        else:
            flag = False
            break
# print k
if flag and k > 0:
    for i in xrange(n / 2 + 1):
        if k <= 0:
            break
        # print i
        # print 'num[i] =', num[i], " num[numOrig] =", numOrig[i], \
        #	" num[n - i - i] =", num[n - i - 1], " numOrig[n - i - 1] =", numOrig[n - i - 1]
        if num[i] == numOrig[i] and num[n - i - 1] == numOrig[n - i - 1] and num[i] != '9':
            if i == n - i - 1:
                num[i] = num[n - i - 1] = '9'
                k -= 1

            elif k > 1:
                num[i] = num[n - i - 1] = '9'
                k -= 2
        elif num[i] != '9':
            num[i] = num[n - i - 1] = '9'
            k -= 1


if flag:
    print ''.join(num)

else:
    print -1
