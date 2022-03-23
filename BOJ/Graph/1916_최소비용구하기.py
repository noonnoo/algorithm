import sys
import heapq
read = sys.stdin.readline

INF = float('inf')
N = int(read())
M = int(read())

costs = [ {} for i in range(N)]             # {a:b} i에서 a까지 가는데 걸리는 비용 b 
from_start = [ INF for i in range(N) ]      # 시작점에서 i까지 가는데 걸리는 비용, 갱신됨 

for m in range(M):
    city1, city2, c = map(int, read().split())
    if (city2-1) in costs[city1-1]:
        costs[city1-1][city2-1] = min(c, costs[city1-1][city2-1])
    else:
        costs[city1-1][city2-1] = c
start, end = map(lambda ct : int(ct) - 1, read().split())

hq = []                                     # 비용이 가장 적은 도시를 pop하는 최소힙
heapq.heappush(hq, [start, 0])

while hq:
    curr, curr_cst = map(lambda c:c, heapq.heappop(hq))     # 현재 위치, start에서 현재까지의 cost
    if from_start[curr] < curr_cst:                         # 비용이 이전에 계산한 것보다 크면 pass
        continue
    for next, to_next  in costs[curr].items():              # 현재위치 인접 next, curr에서 next까지 cost
        next_cst = curr_cst + to_next                       # start에서 curr 거쳐서 next까지 cost
        if next_cst < from_start[next]:                     
            from_start[next] = next_cst                     # 이전 계산보다 cost 싸면 갱신
            heapq.heappush(hq, [next, next_cst])            # 싸게 갱신한것 heap에 추가

print(from_start[end])