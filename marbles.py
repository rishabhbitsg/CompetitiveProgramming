for t in xrange(int(raw_input())):
    n, k = map(int, raw_input().split())

    if k == 1:
        print 1
    elif n == 1:
        print 1
    elif n == k:
        print 1
    else:
        ans = 1
        temp = n - 1
        for i in xrange(min(k - 1, n - k)):
            ans *= temp
            temp -= 1

        for i in xrange(1, min(k, n - k + 1)):
            ans /= i
        print ans
