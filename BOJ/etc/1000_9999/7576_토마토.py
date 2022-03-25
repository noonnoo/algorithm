import sys
from collections import deque
read = sys.stdin.readline

M,N = map(int, read().split())
boxes = [ list(map(int, read().split())) for _ in range(N) ]
direction = [[0,-1],[-1,0],[0,1],[1,0]]
unriped, days = 0, -1

dq = deque()

for i in range(N):
    for j in range(M):
        if boxes[i][j] == 1:
            dq.append([i,j,boxes[i][j]])
        elif boxes[i][j] == 0:
            unriped += 1

if unriped == 0:
    days = 0

while unriped and dq:
    i, j, day = dq.popleft()

    for d in direction:
        if i + d[0] < 0 or i + d[0] >= N or j + d[1] < 0 or j + d[1] >= M:
            continue
        if  boxes[i + d[0]][j + d[1]] == 0:
            boxes[i + d[0]][j + d[1]] = day + 1
            unriped -= 1
            dq.append([i + d[0], j + d[1], day + 1])
    if unriped == 0:
        days = day
        break

print(days)