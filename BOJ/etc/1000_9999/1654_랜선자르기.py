from math import floor
import sys
read = sys.stdin.readline

K, N = map(int, read().split())
cables = [ int(read()) for _ in range(K) ]

mini, maxi= 1, max(cables)

while mini <= maxi:
    mid = floor((mini + maxi) / 2)
    nums = 0

    for cable in cables:
        nums += floor(cable / mid)
    if nums >= N:
        mini = mid + 1
    else:
        maxi = mid - 1

print(maxi)