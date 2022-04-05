import sys
from collections import deque
read = sys.stdin.readline

n, m = map(int, read().split())
island = []
visit = [[False for col in range(m)] for row in range(n)]
queue = deque()

for row in range(n):
    island.append(read())
    for col in range(m):
        if island[row][col] == '2':
            queue.append([row, col])
            visit[row][col] = 1
            break

# BFS
direction = [[-1,0],[0,-1],[0,1],[1,0]]

while queue:
    r, c = queue.popleft()
    num = visit[r][c]

    for d in direction:
        nr = r + d[0]
        nc = c + d[1]
        if (nr < 0) or (nr >= n) or (nc < 0) or (nc >= m) or (island[nr][nc] == '1') or visit[nr][nc]:
            continue
        if island[nr][nc] > '2':
            print("TAK", num, sep="\n")
            exit(0)
        visit[nr][nc] = num + 1
        queue.append([nr, nc])
print("NIE")