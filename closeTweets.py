n, k = map(int, raw_input().split())

status = [0] * n
sum = 0
last = 0

for i in xrange(1, k + 1):
    message = raw_input()
    if message == "CLOSEALL":
        sum = 0
        last = i
    else:
        x = int(message.split()[1]) - 1
        if status[x] <= last:
            status[x] = i
            sum += 1
        else:
            status[x] = 0
            sum -= 1
    print sum
