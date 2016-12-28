for t in xrange(int(raw_input())):
    n, k = map(int, raw_input().split())

    if k == 0:
        for i in xrange(1, n + 1):
            print i,
        print

    elif n % 2 != 0:
        print -1

    else:
        marked = [False] * (n + 1)
        position = [-1] * (n + 1)
        flag = True
        for i in xrange(1, n + 1):
            if not marked[i] and i + k <= n:
                position[i] = i + k
                marked[i + k] = True

            elif marked[i]:
                position[i] = i - k

            else:
                flag = False
                break

        if flag:
            for i in xrange(1, n + 1):
                print position[i],
            print
        else:
            print -1
