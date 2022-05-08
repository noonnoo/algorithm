import sys
read = sys.stdin.readline

answer = 0
N, M, L = map(int, read().split())
spots = list(map(lambda x:int(x)+1, read().split()))
spots.append(1)
spots.append(L+1)
spots.sort()

start, end = 1, spots[-1]
while start <= end:
    mid = (start + end) // 2
    newSpot = 0

    for i in range(1, len(spots)):
        if spots[i] - spots[i-1] > mid:
            newSpot += (spots[i] - spots[i-1] - 1) // mid
    
    if newSpot > M:
        start = mid + 1
    else:
        end = mid - 1
        answer = mid
        
print(answer)